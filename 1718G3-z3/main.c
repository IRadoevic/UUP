#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50], newString[50] = "";
    gets(string);
    int insertPoint = 0, seekPoint = 0;
    for(int i = 0; i < strlen(string) - 1; i++)
    {
        char ch = string[i];
        if(ch == '-')
        {
            newString[insertPoint] = ch;
            insertPoint++;
            seekPoint = insertPoint;
        }
        else
        {
            int f = 1;
            for(int j = seekPoint; j < insertPoint; j++)
            {
                if(string[i] == newString[j])
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
    puts(newString);
    return 0;
}
