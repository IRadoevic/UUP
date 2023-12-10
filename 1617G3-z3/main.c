#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    gets(string);
    char *token;
    char newString[50] = "";
    char copiedString[50] = "";
    strcpy(copiedString, string);
    token = strtok(string, "-");
    strcat(newString, token);
    strcat(newString, "-");
    int length;
    while(token = strtok(NULL, "-"))
    {
        length = strlen(token);
        char c = token[length - 1];
        for(int i = length - 2; i >= 0; i--)
        {
            token[i + 1] = token[i];
        }
        token[0] = c;
        strcat(newString, token);
        strcat(newString, "-");
    }
    char c = newString[strlen(newString) - 1 - length];
    for(int i = strlen(newString) - 1 - length; i < strlen(newString) - 1; i++)
    {
        newString[i] = newString[i + 1];
    }
    newString[strlen(newString) - 2] = c;
    newString[strlen(newString) - 1] = 0;
    puts(newString);
    return 0;
}
