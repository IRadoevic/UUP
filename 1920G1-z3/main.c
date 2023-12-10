#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkIfPalindrom(char *token)
{
    int f = 1;
    for(int i = 0; i < strlen(token) / 2; i++)
    {
        if(token[i] != token[strlen(token) - 1 - i])
        {
            f = 0;
        }
    }
    return f;
}

void rotateString(char *token)
{
    for(int i = 0; i < strlen(token) / 2; i++)
    {
        char tmp = token[i];
        token[i] = token[strlen(token) - 1 - i];
        token[strlen(token) - 1 - i] = tmp;
    }
}

int main()
{
    char string[50], *token, newString[50] = "";
    gets(string);
    token = strtok(string, " ");
    do
    {
        if(checkIfPalindrom(token))
        {
            strcat(newString, strupr(token));
            strcat(newString, " ");
        }
        else
        {
            rotateString(token);
            strcat(newString, token);
            strcat(newString, " ");
        }
    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
