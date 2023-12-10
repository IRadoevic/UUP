#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int iteration, int bottom, int n)
{
    if(iteration == n)
    {
        if(iteration % 2)
        {
            return sqrt((double)iteration/bottom);
        }
        return sqrt((double)iteration/bottom/bottom);
    }
    if(iteration % 2)
    {
        return sqrt((double)iteration/bottom + bottom*rekurzivna(iteration + 1, bottom + 1, n));
    }
    return sqrt((double)iteration/bottom/bottom + rekurzivna(iteration + 1, bottom + 1, n));
}

double iterativna(int n)
{
    int bottom = n + 1, top = n;
    double result;
    if(n % 2)
    {
        result = sqrt((double)top/bottom);
    }
    else
    {
        result = sqrt((double)top/bottom/bottom);
    }
    top--, bottom--;
    for(; top > 0; top--)
    {
        if(top % 2)
        {
            result = sqrt((double)top/bottom + bottom*result);
        }
        else
        {
            result = sqrt((double)top/bottom/bottom + result);
        }
        bottom--;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, 2, n));
    printf("%lf", iterativna(n));
    return 0;
}
