#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *rotateString(char *token)
{
    for(int i = 0; i < strlen(token) / 2; i++)
    {
        char temp = token[i];
        token[i] = token[strlen(token) - 1 - i];
        token[strlen(token) - 1 - i] = temp;
    }
}

int main()
{
    char string[50], newString[50] = "", *token;
    gets(string);
    token = strtok(string, " ");
    do
    {
        if(strlen(token) % 2)
        {
            rotateString(token);
        }
        strcat(newString, token);
        strcat(newString, " ");

    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
