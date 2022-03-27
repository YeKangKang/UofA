/* execute.c - code used by small shell to execute commands */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>
#include	<fcntl.h>

int execute3(char* argument[], int max, int ignore[], char* redirect[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors
 */
{
	int	pid ;
	int	child_info = -1;

	if ( argument[0] == NULL ) {		/* nothing succeeds	*/
		return 0;
	}

	int child = 0;
	int i = 0;
	int prev_pipe[2];
	int new_pipe[2];
	for(i; i < max; i++) {
		if (i != max - 1) {// If not the final arg
			pipe(new_pipe);
		}

		child = fork();                 // fork and handle Error
		if(child < 0) {
			printf("Error");
		}

		if(child == 0){// Child
			if(i != 0) {// If not the first arg
				// redirect input to prev
				dup2 (prev_pipe[0], 0);
				close(prev_pipe[0]);
			}
			if(i != max - 1) {// If not the final arg
				// redirect output to new
				dup2(new_pipe[1], 1);
				close(new_pipe[1]);
			}

			if(redirect[0] != NULL && i == 0) {
				int filefd_in = open(redirect[0], O_RDONLY, 0);
				dup2 (filefd_in, 0);        // red for stdin
			}
			
			if(redirect[1] != NULL && i == max - 1) {// Redirect stdout to file
				int filefd_out = open(redirect[1], O_WRONLY | O_CREAT, 0644);
				dup2 (filefd_out, 1);       // red for stdout
			}

			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			execvp(argument[ignore[i]], &argument[ignore[i]]);
			perror("Error");
			exit(1);
		}else {// Parent
			wait(NULL);
			if(i != 0) {// If not the first arg
				//close prev
				close(prev_pipe[0]);
			}
			if(i != max - 1) {// If not the final arg
				prev_pipe[0] = new_pipe[0];
				prev_pipe[1] = new_pipe[1];
				close(prev_pipe[1]);
			}
		}
	}

	return child_info;
}