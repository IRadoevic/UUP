#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int iteration, int lowTop, int highTop, int bottom)
{
    if(bottom == 2)
    {
        if(iteration % 2)
        {
            return sqrt((double)highTop/bottom);
        }
        return sqrt((double)lowTop/bottom);
    }
    if(iteration % 2)
    {
        return sqrt((double)highTop/bottom + rekurzivna(iteration + 1, lowTop, highTop - 1, bottom - 2));
    }
    return sqrt((double)lowTop/bottom + rekurzivna(iteration + 1, lowTop + 1, highTop, bottom - 2));
}

double iterativna(int n)
{
    int lowTop = n/2;
    int highTop = n/2 + 1;
    double result;
    int bottom = 2;
    if(n % 2)
    {
        result = sqrt((double)highTop / bottom);
        highTop++;
    }
    else
    {
        result = sqrt((double)lowTop / bottom);
        lowTop--;

    }
    bottom += 2;
    for(int iteration = n - 1; iteration > 0; iteration--)
    {
        if(iteration % 2)
        {
            result = sqrt((double)highTop / bottom + result);
            highTop += 1;
        }
        else
        {
            result = sqrt((double)lowTop / bottom + result);
            lowTop -= 1;
        }
        bottom += 2;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, 1, n, n*2));
    printf("%lf\n", iterativna(n));
    return 0;
}
