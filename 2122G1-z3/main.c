#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findSubstrings(char string[50], int p, char *pointer)
{
    char substring[4] = "";
    for(int i = 0; i < 3; i++)
    {
        substring[i] = string[p + i];
    }
    substring[3] = '\0';
    strcpy(pointer, substring);
}

int doesItContain(int start, int finish, char string[50], char substring[3])
{
    char *pokazivac = string;
    for(int i = 0; i < strlen(string); i++)
    {
        if(strstr(pokazivac, substring) >= start && strstr(pokazivac, substring) <= finish)
        {
            return 1;
        }

        else if(strstr(pokazivac, substring) > string + finish)
            return 0;
        pokazivac++;
    }
    return 0;
}

int main()
{
    char string[50], copiedString[50], *token, temp[4];
    gets(string);
    strcpy(copiedString, string);
    token = strtok(string, " ");
    char *spaceTwo, *spaceOne = copiedString;
    do
    {
        if(strlen(token) < 3)
        {
            continue;
        }
        for(int i = 0; i <= strlen(token) - 3; i++)
        {
            findSubstrings(token, i, temp);
            spaceOne = copiedString;
            while(spaceOne)
            {
                spaceTwo = strchr(spaceOne + 1, ' ');
                if(doesItContain(spaceOne, spaceTwo, copiedString, temp))
                {
                    /*for(int i = spaceOne; i <= spaceTwo; i++)
                    {
                        putchar(copiedString[i]);
                    }*/
                    puts(temp);
                    printf("saadrzi, %s\n", spaceOne);

                }
                spaceOne = spaceTwo;
            }
        }
    }while(token = strtok(NULL, " "));

    return 0;
}
