//
// Created by dingjianwei on 10/11/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int execute(char * argv[])
{
    int pid;
    int child_info=-1;
    if(argv[0]==NULL)
    {
        return 0;
    }
    if((pid=fork())==-1)
    {
        perror("fork");
    }
    else if(pid==0)
    {
        signal(SIGINT,SIG_DFL);
        signal(SIGQUIT,SIG_DFL);
        execvp(argv[0],argv);
        perror("cannot execute command");
        exit(1);
    }
    else
    {
        if(wait(&child_info)==-1)
        {
            perror("wait");
        }
        return child_info;
    }
}
