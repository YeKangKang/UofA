/**  smsh1.c  small-shell version 1
 **		first really useful version after prompting shell
 **		this one parses the command line into strings
 **		uses fork, exec, wait, and ignores signals
 **/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include 	<glob.h>
#include	"smsh4.h"

#define	DFL_PROMPT	"> "

int main()
{
	char	*cmdline, *prompt, **arglist;
	int	result;
	void	setup();

	prompt = DFL_PROMPT ;
	setup();
    
    // loop and coutn the total num of char(arguments)
	while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){
		int argu_num = 0;
		int i;
		for(i = 0; i < 255; i++) {
			if(cmdline[i] == ' ') {
				argu_num++;
			}
		}

		if ( (arglist = splitline(cmdline)) != NULL  ) {
            // define location of pipe
			int pipes = 0;
            int ignore[argu_num];			//
			ignore[0] = 0;
			int glb_num = 0;
			char *redirect[2] = {NULL, NULL};
			glob_t glb_result;
			//sets the pipe to NULL
			for(i = 0; i < argu_num+1; i++) {

	            if(*arglist[i] == '|') {// if the input is '|', next
	                pipes++;
					ignore[pipes] = i+1;
					arglist[i] = NULL;
	            }else if (*arglist[i] == '<') {// save input
					redirect[0] = arglist[i+1];
					arglist[i] = NULL;
				}else if (*arglist[i] == '>') {// save output
					redirect[1] = arglist[i+1];
					arglist[i] = NULL;
				} else if (wildcard(arglist[i])) {
					glb_num = 1;                    // check glob
					glb_result.gl_offs = i;         // set gl_offset
					glob(arglist[i],GLOB_DOOFFS, NULL, &glb_result);
					
					int j;
					for (j = 0; j < i; j++) {// move offset into glb
						glb_result.gl_pathv[j] = arglist[j];
					}
				}
	        }
			if (glb_num == 0) {
				result = execute4(arglist,pipes+1,ignore, redirect);
			} else if (glb_num == 1) {
				result = execute4(glb_result.gl_pathv,pipes+1,ignore, redirect);             // execute arg with execute4 func
				globfree(&glb_result);
			}
			freelist(arglist);
		}
		free(cmdline);
	}
	return 0;
}

// wildcard
int wildcard(char* arglist) {
	int j = 0;
	// while until meet end of line
	while (arglist[j] != '\0' || arglist != NULL) {
		if(arglist[j] == '*') {
			return 1;               // return True
		}
		j++;
	}
	return 0;                       // return False
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
	signal(SIGINT,  SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
	fprintf(stderr,"Error: %s,%s\n", s1, s2);
	exit(n);
}
