#include <stdio.h>
#include <string.h>

void eval(char*);

int main(int argc, char const *argv[])
{
    char expr[128];

    puts("Welcome to PImpScript!");
    printf("> ");
    fgets(expr, 128, stdin);
    eval(expr);
    
    return 0;
}

void eval(char *statement)
{
    char *token;
    const char *delim = " ";
    token = strtok(statement, delim);
    while (token != NULL)
    {
        printf("Token: %s\n", token);

        token = strtok(NULL, delim);
    }
}