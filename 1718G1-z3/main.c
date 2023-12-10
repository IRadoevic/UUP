#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50], newString[50] = "";
    gets(string);
    char *token;
    token = strtok(string, " ");
    do
    {
        if(strstr(newString, token) == NULL)
        {
            strcat(newString, token);
            strcat(newString, " ");
        }
    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
