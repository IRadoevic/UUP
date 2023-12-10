#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int distanceBetween(char *token)
{
    int minDist = INT_MAX, curDist;
    for(int i = 0; i < strlen(token) - 1; i++)
    {
        for(int j = i + 1; j < strlen(token); j++)
        {
            char stI = token[i], stJ = token[j];
            if(stI == stJ)
            {
                curDist = j - i;
                if(curDist < minDist)
                {
                    minDist = curDist;
                }
            }
        }
    }
    return minDist;
}

int main()
{
    char string[50], *token;
    gets(string);
    token = strtok(string, " ");
    do
    {
        if(distanceBetween(token) != INT_MAX)
        {
            printf("%s %d\n", token, distanceBetween(token) - 1);
        }
    }while(token = strtok(NULL, " "));
    return 0;
}
