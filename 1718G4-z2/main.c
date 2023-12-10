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
    if(m == 1)
    {
        printf("%d", n);
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        matrix[m - 1 - i][i] = n % 10;
        matrix[m - 1 - i][m - 1 -i] = n % 10;
        n /= 10;
    }
    for(int i = 0; i <= m/2; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j > i && j < m - 1 - i)
            {
                matrix[i][j] = ((matrix[i][i] == 0) ? 9 : matrix[i][i] - 1);
            }
            else if(i != j && i+j != m-1)
            {
                matrix[i][j] = (matrix[i][i] + 1) % 10;
            }
        }
    }
    for(int i = m/2 + 1; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j < i && j > m - 1 - i)
            {
                matrix[i][j] = ((matrix[i][i] == 0) ? 9 : matrix[i][i] - 1);
            }
            else if(i != j && i+j != m-1)
            {
                matrix[i][j] = (matrix[i][i] + 1) % 10;
            }
        }
    }
    printMatrix(m, matrix);
    return 0;
}
