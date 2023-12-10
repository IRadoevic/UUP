#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringFlip(char string[50])
{
    for(int i = 0; i < strlen(string)/2; i++)
    {
        char tmp = string[i];
        string[i] = string[strlen(string) - 1 - i];
        string[strlen(string) - 1 - i] = tmp;
    }
}

int main()
{
    char string[50], copiedString[50] = "", token[20], flippedToken[50] = "";
    gets(string);
    strcpy(copiedString, string);
    token = strtok(string, " ");
    do
    {
        strcpy(flippedToken, token);
        puts(flippedToken);
        /*stringFlip(flippedToken);
        puts(flippedToken);*/
    }while(token = strtok(NULL, " "));
    return 0;
}
