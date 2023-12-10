#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
5 5
2 3 5 7 5
3 5 9 2 8
1 8 2 5 6
7 3 4 5 4
1 3 9 6 5

*/


int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int arrMinColumn[m];
    int arrMinRow[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
            if(i == 0)
            {
                arrMinColumn[j] = matrix[i][j];
            }
            if(j == 0)
            {
                if(matrix[i][j] < arrMinColumn[j])
                {
                    arrMinColumn[j] = matrix[i][j];
                }
                arrMinRow[i] = matrix[i][j];
            }
            if(i && j)
            {
                if(matrix[i][j] < arrMinColumn[j])
                {
                    arrMinColumn[j] = matrix[i][j];
                }
                if(matrix[i][j] < arrMinRow[i])
                {
                    arrMinRow[i] = matrix[i][j];
                }
            }

        }
    }
    printf("\n");
    int result[n][m];
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                result[i][j] = min(arrMinColumn[j], arrMinRow[i]);
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
