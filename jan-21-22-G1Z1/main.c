#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
5
1 2 3 4 5
6 7 8 9 9
1 2 3 4 5
6 5 8 7 5
2 3 4 5 6
*/


int findTheLargest(int n, int mat[n][n], int ip, int jp)
{
    int maxi = INT_MIN;
    int i = ip, j = jp;
    i--, j--;
    while(i >= 0 && j >= 0)
    {
        if(mat[i][j] > maxi)
            maxi = mat[i][j];
        i--;
        j--;
    }
    i = ip, j = jp;
    i++, j++;
    while(i < n && j < n)
    {
        if(mat[i][j] > maxi)
            maxi = mat[i][j];
        i++;
        j++;
    }
    i = ip, j = jp;
    i++, j--;
    while(i < n && j >= 0)
    {
        if(mat[i][j] > maxi)
            maxi = mat[i][j];
        i++;
        j--;
    }
    i = ip, j = jp;
    i--, j++;
    while(i >= 0 && j < n)
    {
        if(mat[i][j] > maxi)
            maxi = mat[i][j];
        i--;
        j++;
    }
    return maxi;
}

int main()
{
    int n;
    scanf("%d", &n);
    int mat1[n][n], mat2[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int maxi = findTheLargest(n, mat1, i, j);
            mat2[i][j] = maxi;
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
