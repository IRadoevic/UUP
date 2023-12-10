#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    int prevNmb = INT_MAX, maxIter = 0, counter = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i % 2)
            {
                if(matrix[i][n - 1 - j] > prevNmb)
                {
                    prevNmb = matrix[i][n - 1 -j];
                    counter++;
                }
                else
                {
                    if(counter > maxIter)
                        maxIter = counter;
                    counter = 1;
                    prevNmb = matrix[i][n - 1 -j];
                }
            }
            else
            {
                if(matrix[i][j] > prevNmb)
                {
                    prevNmb = matrix[i][j];
                    counter++;
                }
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
