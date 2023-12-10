#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int top, int iteracija, int n)
{
    if(iteracija == n)
    {
        return sqrt((double)top/iteracija/iteracija);
    }
    int newTop = top;
    if(iteracija < n/2)
    {
        newTop = top - 1;
    }
    else if(iteracija == n/2 && n % 2)
    {
        newTop = top - 1;
    }
    else if(iteracija == n/2)
    {

    }
    else
    {
        newTop = top + 1;
    }
    return sqrt((double)top/iteracija/iteracija + rekurzivna(newTop, iteracija+1, n));
}

double iterativna(int n)
{
    int top = n, bottom = n;
    double result = sqrt(1.0/top);
    bottom--;
    for(; bottom > 0; bottom--)
    {
        if(bottom > n/2)
        {
            top--;
        }
        else if(bottom == n/2 && n % 2 == 0)
        {

        }
        else
        {
            top++;
        }
        result = sqrt((double)top/bottom/bottom + result);
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(n, 1, n));
    printf("%lf", iterativna(n));
    return 0;
}
