#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toUpper(char a)
{
    if(a >= 'a' && a <= 'z')
        a = a - 'a' + 'A';
    return a;
}

int findTheLength(char *string, int curPosition)
{
    int maxLength = 0, curLength = 0;
    for(int i = curPosition + 1; i < strlen(string); i++)
    {
        char ch1 = toUpper(string[i]), ch2 = toUpper(string[curPosition]);
        if(ch1 == ch2)
        {
            curLength = i - curPosition;
            if(curLength > maxLength)
            {
                maxLength = curLength;
            }
        }
    }
    return maxLength + 1;
}

int main()
{
    char string[50];
    gets(string);
    int maxi = 0;
    for(int i = 0; i < strlen(string); i++)
    {
        int a = findTheLength(string, i);
        if(a > maxi)
        {
            maxi = a;
        }
    }
    printf("duzina %d\n", maxi);
    for(int i = 0; i < strlen(string); i++)
    {
        int a = findTheLength(string, i);
        if(a == maxi)
        {
            for(int j = i; j < i + maxi; j++)
            {
                printf("%c", string[j]);
            }
            printf(" ");
        }
    }
    return 0;
}
