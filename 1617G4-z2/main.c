#include <stdio.h>
#include <stdlib.h>

/**
5 5
2 3 5 2 1
3 5 1 2 1
1 2 2 5 3
7 3 2 5 4
1 3 3 1 5
*/

int main()
{
    int n, m;
    scanf("%d %d", &n , &m);
    int matrix[n][m], newMatrix[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j == 0)
            {
                newMatrix[i][j] = matrix[i][j + 1];
            }
            else if(j == m-1)
            {
                newMatrix[i][j] = matrix[i][j - 1];
            }
            else
            {
                newMatrix[i][j] = matrix[i][j-1] + matrix[i][j + 1];
            }
            printf("%d ", newMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
