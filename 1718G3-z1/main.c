#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int iteration, int top, int bottom, int n)
{
    if(iteration == n)
    {
        return sqrt((double)top/bottom);
    }
    return sqrt((double)top/bottom + rekurzivna(iteration + 1, top - 11, bottom + iteration, n));
}

double iterativna(int n)
{
    int top = 10;
    int bottom = n + (double)((n-1)*n/2);
    double result = sqrt((double)top/bottom);
    bottom -= n - 1;
    top += 11;
    for(int iteration = n - 2; iteration >= 0; iteration--)
    {
        result = sqrt((double)top/bottom + result);
        bottom -= iteration;
        top += 11;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n*11-1, n, n));
    printf("%lf", iterativna(n));
    return 0;
}
