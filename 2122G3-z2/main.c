#include <stdio.h>
#include <stdlib.h>

/**
4 5
1 2 2 2
6 3 1 1
5 8 1 1
6 3 3 1
7 2 1 2
*/


void printMatrix(int n, int m, int matrix[n][m])
{
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int findMaxElOfColumn(int n, int m, int j, int matrix[n][m])
{
    int max = matrix[0][j];
    for(int i = 1; i < n; i++)
    {
        if(matrix[i][j] > max)
            max = matrix[i][j];
    }
    return max;
}

void rotateColumnByOne(int n, int m, int matrix[n][m], int j)
{
    int temp;
    temp = matrix[n - 1][j];
    for(int i = n - 1; i > 0; i--)
    {
        matrix[i][j] = matrix[i - 1][j];
    }
    matrix[0][j] = temp;
}

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    int matrix[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int j = 0; j < m; j++)
    {
        int flag = 1;
        for(int i = 0; i < n/2; i++)
        {
            if(matrix[i][j] != matrix[n - 1 - i][j])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
        {
            int max = findMaxElOfColumn(n, m, j, matrix);
            for(int k = 0; k < max; k++)
                rotateColumnByOne(n, m, matrix, j);
        }
    }
    printMatrix(n, m, matrix);
    return 0;
}
