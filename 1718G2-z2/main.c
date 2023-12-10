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
    if(m % 2)
    {
        for(int i = m - 1; i >= 0; i--)
        {
            matrix[m/2][i] = n % 10;
            matrix[m/2 + 1][i] = n % 10;
            n /= 10;
        }
        if((m / 2) % 2)
        {
            for(int i = m/2 - 1; i >= 0; i--)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2 == 0)
                    {
                        matrix[i][j] = (matrix[i + 1][j] + 1) % 10;
                    }
                    else
                    {
                        matrix[i][j] = matrix[i + 1][j];
                    }
                }
            }
            for(int i = m/2 + 2; i < m; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2)
                    {
                        matrix[i][j] = ((matrix[i-1][j] == 0) ? 9 : matrix[i-1][j] - 1);
                    }
                    else
                    {
                        matrix[i][j] = matrix[i - 1][j];
                    }
                }
            }
        }
        else
        {
            for(int i = m/2 - 1; i >= 0; i--)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2)
                    {
                        matrix[i][j] = (matrix[i + 1][j] + 1) % 10;
                    }
                    else
                    {
                        matrix[i][j] = matrix[i + 1][j];
                    }
                }
            }
            for(int i = m/2 + 2; i < m; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2 == 0)
                    {
                        matrix[i][j] = ((matrix[i-1][j] == 0) ? 9 : matrix[i-1][j] - 1);
                    }
                    else
                    {
                        matrix[i][j] = matrix[i - 1][j];
                    }
                }
            }
        }

    }
    else
    {
        for(int i = m - 1; i >= 0; i--)
        {
            matrix[m/2][i] = n % 10;
            matrix[m/2 - 1][i] = n % 10;
            n /= 10;
        }
        if((m/2) % 2 == 0)
        {
            for(int i = m/2 - 2; i >= 0; i--)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2 == 0)
                    {
                        matrix[i][j] = (matrix[i + 1][j] + 1) % 10;
                    }
                    else
                    {
                        matrix[i][j] = matrix[i + 1][j];
                    }
                }
            }
            for(int i = m/2 + 1; i < m; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2)
                    {
                        matrix[i][j] = ((matrix[i-1][j] == 0) ? 9 : matrix[i-1][j] - 1);
                    }
                    else
                    {
                        matrix[i][j] = matrix[i - 1][j];
                    }
                }
            }
        }
        else
        {
            for(int i = m/2 - 2; i >= 0; i--)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2)
                    {
                        matrix[i][j] = (matrix[i + 1][j] + 1) % 10;
                    }
                    else
                    {
                        matrix[i][j] = matrix[i + 1][j];
                    }
                }
            }
            for(int i = m/2 + 1; i < m; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i % 2 == 0)
                    {
                        matrix[i][j] = ((matrix[i-1][j] == 0) ? 9 : matrix[i-1][j] - 1);
                    }
                    else
                    {
                        matrix[i][j] = matrix[i - 1][j];
                    }
                }
            }
        }
    }
    printMatrix(m, matrix);
    return 0;
}
