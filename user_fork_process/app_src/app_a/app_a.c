/*app_a.c*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib_common.h"

#define ERR_EXIT(m) \
    do\
    {\
        log(m);\
        exit(EXIT_FAILURE);\
    }\
    while (0)\

int main(void)
{
    pid_t pid;
    log("\n");
    log("before calling fork,calling process pid = %d\n",getpid());
    pid = fork();

    if(pid == -1)
        ERR_EXIT("fork error");

    if(pid == 0){
        log("[child process] pid = %d,parent's pid = %d\n",getpid(),getppid());
	exit(99);
    }
    if(pid > 0){
        log("[parent process] pid =%d ,child's pid = %d\n",getpid(),pid);
        int stat_val;
	pid_t child_pid;
	
        log("[parent process] wait child process finish...\n");
        child_pid = wait(&stat_val);
        log("[parent process] child has finished: pid=%d\n",child_pid);

        if(WIFEXITED(stat_val)){
	    log("[parent process] child exit with code %d\n", WEXITSTATUS(stat_val));
        }
        else{
	    log("[parent process] child terminated abnormally\n");
        }
 	
    }

    return 0;
}

