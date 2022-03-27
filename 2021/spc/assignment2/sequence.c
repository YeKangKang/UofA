#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
// Read stdin
    char commands[100][257];                                // MAX 100line 256characters(OR 100 lines string)
    int index = 0;
    while (fgets(commands[index],257,stdin)!=NULL)          // GET UNTIL EOF
    {
        //printf("%s\n", commands[index]);
        index++;
    }
    close(0);



    const char* delim = " ";                            // a string of strtok() spliter
    char* ptr = NULL;                                   // save the string ptr that strtok() return
// for each line in commands
    for (int i=0; i<index; i++)
    {
        int length = strlen(commands[i]);
        commands[i][length-1] = '\0';                   // REMOVE "\n" in each line
        char* arguments[30];                            // MAX 10 arguments per commands, given 30 'string' buffer
                                                        // char* is the string in C

        // e.g. {"cal", NULL, "4", NULL, "2020", NULL}
        ptr = strtok(commands[i], delim);
        int temp = 0;
        while (ptr!='\0')                               // while untile meet the end of a line
        {
            arguments[temp] = ptr;
            ptr = strtok(NULL,delim);
            temp++;
        }
        arguments[temp++] = NULL;                       // adding '\0' to last argument
                                                

        // fork()
        int fk = fork();
        // FORK fail
        if (fk < 0)
        {
            printf("Fork fail!\n");
            return 1;
        }
        // child
        else if (fk == 0)
        {
            if (execvp(arguments[0], arguments) == -1)  // if EXECVP fail
            {
                printf("fail EXECVP at %d", i);
                exit(0);
            }
        }
        // parent
        else
        {
            wait(NULL);
        }
    }
    return 0;
}