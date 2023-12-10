#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
int minSusednihKolona(int k, int n, int matrix[n][n])
{
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(k != 0 && k != n-1)
        {
            int mini = (matrix[i][k - 1] < matrix[i][k + 1] ? matrix[i][k - 1] : matrix[i][k + 1]);
            if(mini < min)
                min = mini;
        }
        else if(k != 0)
        {
            if(matrix[i][k - 1] < min)
                min = matrix[i][k - 1];
        }
        else
        {
            if(matrix[i][k + 1] < min)
                min = matrix[i][k + 1];
        }
    }
    return min;
}
int maxSusednihVrsta(int k, int n, int matrix[n][n])
{
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(k != 0 && k != n-1)
        {
            int maxi = (matrix[k - 1][i] < matrix[k+1][i] ? matrix[k+1][i] : matrix[k-1][i]);
            if(maxi > max)
                max = maxi;
        }
        else if(k != 0)
        {
            if(matrix[k - 1][i] > max)
                max = matrix[k - 1][i];
        }
        else
        {
            if(matrix[k + 1][i] > max)
                max = matrix[k + 1][i];
        }
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n], newMatrix[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            newMatrix[i][j] = fabs(maxSusednihVrsta(i, n, matrix) - minSusednihKolona(j, n, matrix));
            printf("%d ", newMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
