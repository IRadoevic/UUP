#include <stdio.h>
#include <stdlib.h>

int noOfDigs(int n)
{
    int counter = 0;
    while(n)
    {
        counter++;
        n/=10;
    }
    return counter;
}

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
    int n, m;
    scanf("%d", &n);
    m = noOfDigs(n);
    int matrix[m][m];
    for(int i = 0; i < m; i++)
    {
        matrix[i][i] = n % 10;
        matrix[m-1-i][i] = n % 10;
        n /= 10;
    }
    for(int j = 0; j <= m/2; j++)
    {
        for(int i = 0; i < m; i++)
        {
            if(i > j && i < m - 1 - j)
            {
                matrix[i][j] = (matrix[j][j] + 1) % 10;
            }
            else if(i != j && i+j != m-1)
            {
                matrix[i][j] = ((matrix[j][j] == 0) ? 9 : matrix[j][j] - 1);
            }
        }
    }
    for(int j = m/2 + 1; j < m; j++)
    {
        for(int i = 0; i < m; i++)
        {
            if(i < j && i > m - 1 - j)
            {
                matrix[i][j] = (matrix[j][j] + 1) % 10;
            }
            else if(i != j && i+j != m-1)
            {
                matrix[i][j] = ((matrix[j][j] == 0) ? 9 : matrix[j][j] - 1);
            }
        }
    }
    printMatrix(m, matrix);
    return 0;
}
