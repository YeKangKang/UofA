/**  smsh1.c  small-shell version 1
 **		first really useful version after prompting shell
 **		this one parses the command line into strings
 **		uses fork, exec, wait, and ignores signals
 **/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"smsh2.h"

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
		int i;
		int argu_num = 0;
		for(i = 0; i < 255; i++) {
			if(cmdline[i] == ' ') {
				argu_num++;
			}
		}


		if ( (arglist = splitline(cmdline)) != NULL  ) {
			// define location of pipe
			int pipes = 0;
			int ignore[argu_num];
			ignore[0] = 0;
			//sets the pipe to NULL
			for(i = 0; i < argu_num+1; i++) {
	            if(*arglist[i] == '|')      {// if the input is '|', next
	                pipes++;
					ignore[pipes] = i+1;
					arglist[i] = NULL;
	            }
	        }
			result = execute2(arglist,pipes+1,ignore);      // execute arg with execute2 func
			freelist(arglist);
		}
		free(cmdline);      // free memory
	}
	return 0;
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