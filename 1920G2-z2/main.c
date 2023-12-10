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
    int n, m, counter = 0;
    scanf("%d %d", &n, &m);
    int matrix[m][m];
    int leftBound = 0, rightBound = m - 1, topBound = 0, bottomBound = m - 1;
    while(counter < m * m)
    {
        for(int i = rightBound; i >= leftBound; i--)
        {
            if(i == leftBound)
                n = (n + 2) % 10;
            matrix[topBound][i] = n;
        }
        topBound++;
        for(int i = topBound; i <= bottomBound; i++)
        {
            if(i == bottomBound)
                n = (n + 2) % 10;
            matrix[i][leftBound] = n;
        }
        leftBound++;
        for(int i = leftBound; i <= rightBound; i++)
        {
            if(i == rightBound)
                n = (n + 2) % 10;
            matrix[bottomBound][i] = n;
        }
        bottomBound--;
        for(int i = bottomBound; i >= topBound; i--)
        {
            if(i == topBound)
                n = (n + 2) % 10;
            matrix[i][rightBound] = n;
        }
        rightBound--;
        counter++;
    }
    printMatrix(m, matrix);
    return 0;
}
