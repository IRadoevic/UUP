#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTheNoOfOccs(char string[], char token[])
{
    int counter = 0;
    char *pointer = string;
    for(int i = 0; i < strlen(string); i++)
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
    char string1[50], string2[30];
    gets(string1);
    gets(string2);
    char substring[50] = "";
    int insertion = 0;
    int a = 0;
    for(int i = 0; i < strlen(string2); i++)
    {
        insertion = 0;
        substring[0] = '\0';
        int f = 1;
        for(int j = 0; j < i; j++)
        {
            if(string2[i] == string2[j])
            {
                f = 0;
            }
        }
        if(f)
        {
            for(int j = 0; j <= strlen(string2); j++)
            {
                if(string2[j] != string2[i])
                {
                    char c = string2[j];
                    substring[insertion] = c;
                    insertion++;
                }
            }
            substring[insertion] = '\0';
            a += findTheNoOfOccs(string1, substring);
        }
    }
    printf("Izlaz: %d", a);
    return 0;
}
