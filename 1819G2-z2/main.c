#include <stdio.h>
#include <stdlib.h>

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
            newMatrix[i][j] = (i ? matrix[i-1][j] : 0) + (j ? matrix[i][j-1] : 0) + (i != n-1 ? matrix[i+1][j] : 0) + (j != n - 1 ? matrix[i][j + 1] : 0) - matrix[i][j];
        }
    }
    printMatrix(n, newMatrix);
    return 0;
}
