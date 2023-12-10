#include <stdio.h>
#include <stdlib.h>

/**
6 8
3 2 6 4 5 8
7 4 3 2 7 1
0 5 6 9 2 3
0 7 9 4 9 4
9 2 2 9 4 9
4 3 2 4 3 2
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

void rotateOnce(int n, int * matrix[n][n])
{
    int tr, br, bl, tl;
    for(int i = 0; i < n / 2; i++)
    {
        tr = matrix[i][n - 1 -i];
        br = matrix[n - 1 - i][n - 1 -i];
        bl = matrix[n - 1 - i][i];
        tl = matrix[i][i];
        for(int j = n - 1 - i; j > i; j--)
        {
            if(j == i + 1)
            {
                matrix[j][n - 1 - i] = tr;
                matrix[n - 1 - i][n - 1 - j] = br;
                matrix[n - 1 - j][i] = bl;
                matrix[i][j] = tl;
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
                matrix[j][n - 1 - i] = matrix[j - 1][n - 1 - i];
                matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - i][n - j];
                matrix[n - 1 - j][i] = matrix[n - j][i];
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int matrix[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < k; i++)
    {
        rotateOnce(n, &matrix);
    }
    printf("\n");
    printMatrix(n, matrix);
    return 0;
}
