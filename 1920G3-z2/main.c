#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    int prevNmb, maxIter = 0, counter = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == 0 && j == 0)
                prevNmb = matrix[i][j] - 6;
            if(j % 2)
            {
                if(matrix[n - 1 - i][j] == prevNmb)
                    counter++;
                else
                {
                    if(counter > maxIter)
                        maxIter = counter;
                    counter = 1;
                    prevNmb = matrix[n - 1 - i][j];
                }
            }
            else
            {
                if(matrix[i][j] == prevNmb)
                    counter++;
                else
                {
                    if(counter > maxIter)
                        maxIter = counter;
                    counter = 1;
                    prevNmb = matrix[i][j];
                }
            }
        }
    }
    printf("%d", maxIter);
    return 0;
}
