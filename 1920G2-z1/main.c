#include <stdio.h>
#include <stdlib.h>

double factoriel(int n)
{
    double f = 1;
    for(int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

double rekurzivna(int lowNmb, int highNmb, int iteration, int n)
{
    if(iteration == n)
    {
        if(iteration % 2)
        {
            return lowNmb+factoriel(highNmb);
        }
        return highNmb+factoriel(lowNmb);
    }
    if(iteration % 2)
    {
        return lowNmb + (double)factoriel(highNmb)/rekurzivna(lowNmb, highNmb, iteration + 1, n);
    }
    return highNmb + (double)factoriel(lowNmb)/rekurzivna(lowNmb + 1, highNmb - 1, iteration + 1, n);
}

double iterativna(int n)
{
    int highNmb = n / 2 + 1, lowNmb;
    double res;
    if(n % 2)
    {
        lowNmb = n / 2 + 1;
        res = lowNmb + factoriel(highNmb);
        lowNmb--;
        highNmb++;
    }
    else
    {
        lowNmb = n / 2;
        res = highNmb + factoriel(lowNmb);
    }
    for(int i = n - 1; i > 0; i--)
    {
        if(i % 2)
        {
            res = lowNmb + (double)factoriel(highNmb)/res;
            lowNmb--;
            highNmb++;
        }
        else
        {
            res = highNmb + (double)factoriel(lowNmb)/res;
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n, 1, n));
    printf("%lf", iterativna(n));
    return 0;
}
