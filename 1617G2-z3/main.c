#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    gets(string);
    int n;
    scanf("%d", &n);

    char *token;
    token = strtok(string, " ");
    char newString[50] = "";
    do
    {
        if(strlen(token) >= n)
        {
            strcat(newString, token);
            strcat(newString, " ");
        }
    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
