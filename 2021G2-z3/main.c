#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findNoOfOccs(char string[50], char token[50])
{
    char *pointer = string;
    int counter = 0;
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
    char string[50], copiedString[50], newString[50] = "", *token;
    gets(string);
    strcpy(copiedString, string);
    token = strtok(string, " ");
    int mini = INT_MAX;
    do
    {
        if(findNoOfOccs(copiedString, token) < mini)
        {
            mini = findNoOfOccs(copiedString, token);
        }
    }while(token = strtok(NULL, " "));
    strcpy(string, copiedString);
    token = strtok(string, " ");
    do
    {
        if(findNoOfOccs(copiedString, token) != mini)
        {
            strcat(newString, token);
            strcat(newString, " ");
        }
    }while(token = strtok(NULL, " "));
    puts(newString);
    return 0;
}
