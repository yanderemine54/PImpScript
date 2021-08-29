#include <stdio.h>
#include <string.h>
#include "repl.h"

static BOOL isPrint = FALSE;
static BOOL isQuit = FALSE;

void eval(char*);

int main(int argc, char const *argv[])
{
    char expr[128];

    puts("Welcome to PImpScript!");
    while (isQuit != TRUE)
    {
        printf("> ");
        fgets(expr, 128, stdin);
        eval(expr);
    }
    return 0;
}

void eval(char *statement)
{
    char *token;
    const char *delim = " ";
    token = strtok(statement, delim);
    while (token != NULL)
    {
        if (strcasecmp(token, "print") == 0)
        {
            isPrint = TRUE;
        }
        else if (strcasecmp(token, "quit") == 0)
        {
            isQuit = TRUE;
            return;
        }
        else if (isPrint == TRUE)
        {
            puts(token);
            isPrint = FALSE;
        }
        else
        {
            printf("Syntax error on %s\n", token);
        }
        
        token = strtok(NULL, delim);
    }
}