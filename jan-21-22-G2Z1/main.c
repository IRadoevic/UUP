#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
4
2 1 4 7
5 3 8 2
6 1 7 9
3 0 4 2

5
2 1 6 5 7
5 4 1 8 2
7 7 3 9 1
6 2 4 5 3
8 5 2 0 6
*/

int findTheValue(int n, int mat[n][n], int i, int j)
{
    int mini = INT_MAX, maxi = INT_MIN;
    int iplus = ((i < n - 1) ? i + 1 : 0);
    int iminus = ((i > 0) ? i - 1 : n - 1);
    int jplus = ((j < n - 1) ? j + 1 : 0);
    int jminus = ((j > 0) ? j - 1 : n - 1);
    //printf("za %d %d, i+ = %d, i- = %d, j+ = %d, j- = %d\n", i, j, iplus, iminus, jplus, jminus);
    if(mat[iminus][jminus] > maxi)
    {
        maxi = mat[iminus][jminus];
        //printf("maxi changed for %d %d\n", iminus, jminus);
    }
    if(mat[iminus][jminus] < mini)
    {
        mini = mat[iminus][jminus];
        //printf("mini changed for %d %d\n", iminus, jminus);
    }
    if(mat[iminus][j] > maxi)
    {
        maxi = mat[iminus][j];
        //printf("maxi changed for %d %d\n", iminus, j);
    }
    if(mat[iminus][j] < mini)
    {
        mini = mat[iminus][j];
        //printf("mini changed for %d %d\n", iminus, j);
    }
    if(mat[iminus][jplus] > maxi)
    {
        maxi = mat[iminus][jplus];
        //printf("maxi changed for %d %d\n", iminus, jplus);
    }
    if(mat[iminus][jplus] < mini)
    {
        mini = mat[iminus][jplus];
        //printf("mini changed for %d %d\n", iminus, jplus);
    }
    ///////////////////////////////
    if(mat[i][jminus] > maxi)
    {
        maxi = mat[i][jminus];
        //printf("maxi changed for %d %d\n", i, jminus);
    }
    if(mat[i][jminus] < mini)
    {
        mini = mat[i][jminus];
        //printf("mini changed for %d %d\n", i, jminus);
    }
    if(mat[i][jplus] > maxi)
    {
        maxi = mat[i][jplus];
        //printf("maxi changed for %d %d\n", i, jplus);
    }
    if(mat[i][jplus] < mini)
    {
        mini = mat[i][jplus];
        //printf("mini changed for %d %d\n", i, jplus);
    }
    ///////////////////////////////
    if(mat[iplus][jminus] > maxi)
    {
        maxi = mat[iplus][jminus];
        //printf("maxi changed for %d %d\n", iplus, jminus);
    }
    if(mat[iplus][jminus] < mini)
    {
        mini = mat[iplus][jminus];
        //printf("mini changed for %d %d\n", iplus, jminus);
    }
    if(mat[iplus][j] > maxi)
    {
        maxi = mat[iplus][j];
        //printf("maxi changed for %d %d\n", iplus, j);
    }
    if(mat[iplus][j] < mini)
    {
        mini = mat[iplus][j];
        //printf("mini changed for %d %d\n", iplus, j);
    }
    if(mat[iplus][jplus] > maxi)
    {
        maxi = mat[iplus][jplus];
        //printf("maxi changed for %d %d\n", iplus, jplus);
    }
    if(mat[iplus][jplus] < mini)
    {
        mini = mat[iplus][jplus];
        //printf("mini changed for %d %d\n", iplus, jplus);
    }
    return (maxi - mini);
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
            int abs = findTheValue(n, mat1, i, j);
            mat2[i][j] = abs;
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
