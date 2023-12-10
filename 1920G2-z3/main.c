#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    gets(string);
    int inseritonPoint = 0, left = 0, right = strlen(string) - 1;
    for(int i = 0; i < strlen(string); i++)
    {
        char c = string[i], cn = string[i + 1];
        if(c == 'n' && cn == 'j' || c == 'l' && cn == 'j')
        {
            string[i] = 'a';
            string[i + 1] = 'a';
        }
    }
    int f = 1;
    while(left < right && f)
    {
        char c = string[left], cn = string[right];
        if(c == ' ')
        {
            left++;
        }
        if(cn == ' ')
        {
            right--;
        }
        if(string[left] != string[right])
        {
            f = 0;
            break;
        }
        left++;
        right--;
    }
    if(f)
    {
        printf("jeste palindrom");
    }
    else
    {
        printf("nije palindrom");
    }
    return 0;
}
