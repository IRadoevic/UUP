#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/**
4
2 2 13 13
5 1 7 19
0 3 1 3
1 2 3 4
*/

void printMatrix(int m, int matrix[m][m])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    int aLargestRow[n], aLargestRowNumber[n];
    int aLowestColumn[n], aLowestColumnNumber[n];
    for(int i = 0; i < n; i++)
    {
        aLowestColumn[i] = INT_MAX;
        aLargestRow[i] = INT_MIN;
        aLargestRowNumber[i] = 0;
        aLowestColumnNumber[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] && matrix[i][j] % 2 == 0 && matrix[i][j] < aLowestColumn[j])
            {
                aLowestColumn[j] = matrix[i][j];
                aLowestColumnNumber[j] = 1;
            }
            else if(matrix[i][j] == aLowestColumn[i])
            {
                aLowestColumnNumber[i]++;
            }
            if(matrix[i][j] % 2 && matrix[i][j] > aLargestRow[i])
            {
                aLargestRow[i] = matrix[i][j];
                aLargestRowNumber[i] = 1;
            }
            else if(matrix[i][j] == aLargestRow[i])
            {
                aLargestRowNumber[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(aLargestRow[i] != INT_MIN)
            printf("red %d: %d %d\n", i + 1, aLargestRow[i], aLargestRowNumber[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(aLowestColumn[i] != INT_MAX)
            printf("kolona %d: %d %d\n", i + 1, aLowestColumn[i], aLowestColumnNumber[i]);
    }
    return 0;
}
