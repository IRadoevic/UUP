#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50], newString[50] = "";
    gets(string);
    int seekPoint = 0, insertPoint = 0, lastDashInNew = 0;
    for(int i = 0; i < strlen(string); i++)
    {
        int f = 0;
        char ch = string[i];
        if(ch == '-')
        {
            newString[insertPoint] = ch;
            seekPoint = i;
            lastDashInNew = insertPoint;
            insertPoint++;
        }
        else
        {
            for(int j = seekPoint; j < i; j++)
            {
                if(string[i] == string[j])
                {
                    f = 1;
                }
            }
            for(int j = lastDashInNew; j < insertPoint; j++)
            {
                if(newString[j] == string[i])
                {
                    f = 0;
                }
            }
            if(f)
            {
                newString[insertPoint] = ch;
                insertPoint++;
            }
        }
    }
    if(newString[strlen(newString) - 1] == '-')
    {
        newString[strlen(newString) - 1] = '\0';
    }
    puts(newString);
    return 0;
}
