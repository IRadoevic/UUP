#include <stdio.h>
#include <stdlib.h>

/**
4
2 6 1 4
3 5 6 8
4 1 8 0
9 6 3 7

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

int max(int a, int b)
{
    if(a % 2 && b % 2)
        return 0;
    if(a % 2)
        return b;
    if(b % 2)
        return a;
    return (a > b) ? a : b;
}

int findMaxEven(int n, int matrix[n][n], int i, int j)
{
    int a = (i) ? matrix[i - 1][j] : 0;
    int b = (i != n - 1) ? matrix[i + 1][j] : 0;
    int c = (j) ? matrix[i][j - 1] : 0;
    int d = (j != n - 1) ? matrix[i][j + 1] : 0;
    return max(a, max(b, max(c, d)));
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
        newMatrix[i][i] = matrix[n - 1 - i][i];
        newMatrix[n - 1 - i][i] = matrix[i][i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && i + j != n - 1)
            {
                newMatrix[i][j] = findMaxEven(n, matrix, i, j);
            }
        }
    }
    printMatrix(n, newMatrix);
    return 0;
}
