#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"
#define DFL_PROMOPT ">"

extern execute(char **);
void setup();
//int fatal(char *, char *, int);
int main() {
    char *cmdline,*prompt,**arglist;
    int result;

    prompt=DFL_PROMOPT;
    setup();

    while((cmdline=next_cmd(prompt,stdin))!=NULL)
    {
        if((arglist=splitline(cmdline))!=NULL)
        {
            result=execute(arglist);
        }
        free(cmdline);
    }
    return 0;
}

void setup()
{
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
}

void fatal(char *s1,char *s2,int n)
{
    fprintf(stderr,"Error: %s,%s\n",s1,s2);
    exit(n);
}