#include <stdio.h>
#include <stdlib.h>

int findTheResult(int n, int mat[n][n], int *rowIndex, int *columnIndex, int maxSame, int i)
{
    int a1[10], a2[10];
    for(int i = 0; i < 10; i++)
    {
        a1[i] = 0;
        a2[i] = 0;
    }
    for(int j = 0; j < n; j++)
    {
        a[mat[i][j]]++;
    }
    for(in)
}

int main()
{
    int n;
    scanf("%d", &n);
    int mat[n][n];
    int rowIndex, columnIndex, maxSame = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int res = findTheResult(int n, int mat[n][n], &rowIndex, &columnIndex, maxSame);
        }
    }
    return 0;
}
