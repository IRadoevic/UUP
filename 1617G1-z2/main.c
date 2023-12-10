#include <stdio.h>
#include <stdlib.h>

int noOfDigs(int n)
{
    int counter = 0;
    while(n)
    {
        counter++;
        n /= 10;
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
    int n;
    scanf("%d", &n);
    int m = noOfDigs(n);
    int matrix[m][m];
    for(int i = m-1; i >= 0; i--)
    {
        matrix[0][i] = n%10;
        n/=10;
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i % 2)
            {
                matrix[i][j] = (matrix[i-1][j] + 9) % 10;
            }
            else
            {
                matrix[i][j] = (matrix[i-1][j] + 8) % 10;
            }
        }
    }
    printMatrix(m, matrix);
    return 0;
}
