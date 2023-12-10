#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    gets(string);
    char *token;
    char newString[50] = "";
   token = strtok(string, " ");
   do
   {
        int tokenLength = strlen(token);
        if(token[0] >= 'a' && token[0] <= 'z' && token[tokenLength - 1] >= 'a' && token[tokenLength - 1] <= 'z')
        {

        }
        else
        {
            strcat(newString, token);
            strcat(newString, " ");
        }
   }
   while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
