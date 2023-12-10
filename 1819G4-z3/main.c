#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTheSum(char *token)
{
    int nmb = 0;
    for(int i = 0; i < strlen(token); i++)
    {
        char ch = token[i];
        nmb += ch - '0';
    }
    return nmb;
}

int main()
{
    char string[50], *token, copiedString[50];
    int array[300];
    int maxi = 0, theSum = 0;
    for(int i = 0; i < 300; i++)
    {
        array[i] = 0;
    }
    gets(string);
    strcpy(copiedString, string);
    token = strtok(string, "-");
    do
    {
        int a = findTheSum(token);
        array[a]++;
        if(array[a] > maxi)
        {
            maxi = array[a];
            theSum = a;
        }
    }while(token = strtok(NULL, "-"));
    printf("Zbir %d, ", theSum);
    token = strtok(copiedString, "-");
    do
    {
        int a = findTheSum(token);
        if(a == theSum)
        {
            printf("%s, ", token);
        }
    }while(token = strtok(NULL, "-"));
    return 0;
}
