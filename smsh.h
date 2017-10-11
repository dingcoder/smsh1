//
// Created by dingjianwei on 10/11/17.
//

#include <wchar.h>

#ifndef SMSH1_SMSH_H
#define SMSH1_SMSH_H
#define YES 1
#define NO 0

char *next_cmd();
char **splitline(char *);
void freelist(char **);
void *emalloc(size_t);
void *erealloc(void *,size_t);
int execuute(char **);
void fatal(char *, char *, int);


#endif //SMSH1_SMSH_H
