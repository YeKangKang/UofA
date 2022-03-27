#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    // get input from stdin
    char commands[100][257];
    int index = 0;
    while (fgets(commands[index],257,stdin)!=NULL) {
        index++;
    }
    close(0);

    // For each command except the FINAL one:
    // new_pipe = the output of the current command
    // For each command except the FIRST one:
    // prev_pipe = the output of the previous command, input of currern command
    const char* delim = " ";
    char* ptr = NULL;
    
    int prev_pipe[2];
    int new_pipe[2];
    if (pipe(prev_pipe) == -1){
            printf("ERROR, prev_pipe FAIL");
            return 1;
    }

    for (int i=0; i<index; i++) {
        // for Line of commend save into arguments
        // after finish the arguments is ready to PIPE
        int length = strlen(commands[i]);
        commands[i][length-1] = '\0';
        char* arguments[30];
        ptr = strtok(commands[i], delim);
        int temp = 0;
        while (ptr!='\0')
        {
            arguments[temp] = ptr;
            ptr = strtok(NULL,delim);
            temp++;
        }
        arguments[temp++] = NULL;


        // creat NEW_PIPE PREV_PIPE and handle error
        if (i != index-1) {
            if (pipe(new_pipe) == -1){
                printf("ERROR, new_pipe FAIL in i = %d\n",i);
                return 1;
            }
        }


        // fork and handle error
        int fk = fork();
        if (fk < 0) {// ERROR
            printf("Fork fail!\n");
            return 1;
        }
        else if (fk == 0) {// child
            // 每次进入if语句都会读取prev_pipe的数据作为stdin的流，等待execvp执行
            // 将execvp执行后的stdout结果写入new_pipe中
            if (i != 0) {// if it's not the first command （因为first不需要从管道内读取数据）
                close(prev_pipe[1]);    // 子进程从管道中读取数据，关闭写端 (close write)
                dup2(prev_pipe[0],0);   // 让argument从管道内读取数据 (read data in pipe and pipe as stdin)
                close(prev_pipe[0]);    // 完成读取，关闭读取端 (close read)
            }
            if (i != index-1) {// if it's not the final command （因为final已经不需要向管道内写入数据）
                close(new_pipe[0]);     // 子进程向new_pipe写入数据，关闭读取端 (close read)
                dup2(new_pipe[1],1);    // 将结果写入管道中 (write data from stdout into pipe)
                close(new_pipe[1]);     // 写入完成，关闭写入端 (close write)
            }
            if (execvp(arguments[0], arguments) == -1)  // if EXECVP fail
            {
                printf("fail EXECVP\n");
                exit(0);
            }
        }
        else {// parent
            if (i != 0) {// if it's not the first command
                close(prev_pipe[1]);
            }
            wait(NULL);
            if (i != index-1) {// if it's not the final command
                prev_pipe[0] = new_pipe[0];
                prev_pipe[1] = new_pipe[1];
            }
        }
    }
    close(prev_pipe[0]);
    close(prev_pipe[1]);
    close(new_pipe[0]);
    close(new_pipe[1]);
    return 0;
}