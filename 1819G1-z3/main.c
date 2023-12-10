#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNoOfOccurances(char token[50], char string[50])
{
    int counter = 0;
    char *pointer = string;
    for(int i = 0; i <= strlen(string) - strlen(token); i++)
    {
        if(strstr(pointer, token) == i + string)
        {
            counter++;
        }
        pointer++;
    }
    return counter;
}

int main()
{
    char string[50], copyOfString[50], *token;
    gets(string);
    strcpy(copyOfString, string);
    int maxOcc = 0, occ = 0;
    char *stringMAxOcc;
    token = strtok(string, " ");
    do
    {
        occ = findNoOfOccurances(token, copyOfString);
        if(occ > maxOcc)
        {
            maxOcc = occ;
            stringMAxOcc = token;
        }
    }while(token = strtok(NULL, " "));
    printf("%s %d",stringMAxOcc, maxOcc);
    return 0;
}
