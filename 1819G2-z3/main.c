#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50], *token, copiedString[50], newString[50] = "";
    gets(string);
    strcpy(copiedString, string);
    token = strtok(string, " ");
    int insertionPoint = 0;
    do
    {
        if(token[0] == '"' && token[strlen(token) - 1] == '"')
        {
            for(int i = 0; i < strlen(token); i++)
            {
                if(token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u' ||
                   token[i] == 'A' || token[i] == 'E' || token[i] == 'I' || token[i] == 'O' || token[i] == 'U')
                {
                    newString[insertionPoint] = token[i];
                    insertionPoint++;
                }
            }
            if(newString[strlen(newString)] != ' ')
            {
                newString[strlen(newString)] = ' ';
                insertionPoint++;
            }
        }
        else
        {
            strcat(newString, token);
            strcat(newString, " ");
            insertionPoint = strlen(newString);
        }
    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
