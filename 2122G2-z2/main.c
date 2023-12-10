#include <stdio.h>
#include <stdlib.h>

/**
5
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2
*/

void printMatrix(int n, int matrix[n][n])
{
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sortColumns(int n, int matrix[n][n])
{
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int k = i + 1; k < n; k++)
            {
                if(matrix[i][j] > matrix[k][j])
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
}

void sortLastRow(int n, int matrix[n][n])
{
    for(int j = 0; j < n - 1; j++)
    {
        for(int k = j + 1; k < n; k++)
        {
            if(matrix[n - 1][j] < matrix[n - 1][k])
            {
                for(int i = 0; i < n; i++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    sortColumns(n, matrix);
    sortLastRow(n, matrix);
    printMatrix(n, matrix);
    return 0;
}
