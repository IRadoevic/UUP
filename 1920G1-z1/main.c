#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int lowNmb, int highNmb, int iteration, int n)
{
    if(iteration == n)
    {
        if(iteration % 2)
        {
            return sqrt((double)lowNmb/highNmb/highNmb);
        }
        else
        {
            return sqrt((double)highNmb/lowNmb/lowNmb);
        }
    }
    if(iteration % 2)
    {
        return sqrt((double)lowNmb/highNmb/highNmb + rekurzivna(lowNmb, highNmb, iteration + 1, n));
    }
    return sqrt((double)highNmb/lowNmb/lowNmb + rekurzivna(lowNmb + 1, highNmb - 1, iteration + 1, n));
}

double iterativna(int n)
{
    int highNmb = n/2 + 1;
    int lowNmb = n/2;
    if(n % 2)
    {
        lowNmb++;
    }
    double result;
    if(n % 2)
    {
        result = sqrt((double)lowNmb/highNmb/highNmb);
        lowNmb--;
        highNmb++;
    }
    else
    {
        result = sqrt((double)highNmb/lowNmb/lowNmb);
    }
    for(int i = n - 1; i > 0; i--)
    {
        if(i % 2)
        {
            result = sqrt((double)lowNmb/highNmb/highNmb + result);
            lowNmb--;
            highNmb++;
        }
        else
        {
            result = sqrt((double)highNmb/lowNmb/lowNmb + result);
        }
    }
    return result;
}


int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n, 1, n));
    printf("%lf", iterativna(n));
    return 0;
}
