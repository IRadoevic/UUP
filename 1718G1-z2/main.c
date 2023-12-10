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
    for(int i = m-1; i >= 0; i--)
    {
        matrix[i][m -1 -i] = n % 10;
        n/=10;
    }
    for(int i = 0; i < m ;i++)
    {
        int iteration = 1;
        for(int j = m - i - 2; j >= 0; j--)
        {
            if(iteration % 2)
            {
                matrix[i][j] = (matrix[i][j+1] == 0) ? 9 : matrix[i][j+1] - 1;
            }
            else
            {
                matrix[i][j] = matrix[i][j + 1];
            }
            iteration++;
        }
    }
    for(int i = 1; i < m ;i++)
    {
        int iteration = 1;
        for(int j = m - i; j < m; j++)
        {
            if(iteration % 2 == 0)
            {
                matrix[i][j] = (matrix[i][j - 1] + 1) % 10;
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
            }
            iteration++;
        }
    }
    printMatrix(m, matrix);
    return 0;
}
