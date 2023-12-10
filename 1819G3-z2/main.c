#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/**
3
5 3 7
3 5 1
2 1 3
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
    int matrix[n][n], newMatrix[n][n];
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
            int maxi = INT_MIN;
            for(int k = 0; k < n; k++)
            {
                for(int t = 0; t < n; t++)
                {
                    if(k != i && t != j)
                    {
                        if(matrix[k][t] > maxi)
                        {
                            maxi = matrix[k][t];
                        }
                    }
                }
            }
            newMatrix[i][j] = matrix[i][j] + maxi;
        }
    }
    printMatrix(n, newMatrix);
    return 0;
}
