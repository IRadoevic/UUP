#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int lowNmb, int highNmb, int stepen, int n)
{
    if(lowNmb == highNmb)
    {
        return(lowNmb + pow(highNmb, stepen));
    }
    int noviStepen;
    if(stepen == n/2)
    {
        noviStepen = 1;
    }
    else
    {
        noviStepen = stepen + 1;
    }
    if(lowNmb % 2)
    {
        return pow(highNmb, stepen) + (double)lowNmb/rekurzivna(lowNmb + 1, highNmb - 1, noviStepen, n);
    }
    return lowNmb + pow(highNmb, stepen)/rekurzivna(lowNmb + 1, highNmb - 1, noviStepen, n);
}

double iterativna(int n)
{
    int highNmb = n, lowNmb = n, stepen;
    double result;
    if(n % 2)
    {
        stepen = 1;
    }
    else
    {
        stepen = n/2;
    }
    result = lowNmb + pow(highNmb, stepen);
    lowNmb--;
    highNmb++;
    if(stepen == 1)
        stepen = n/2;
    else
        stepen--;
    for(;lowNmb > 0; lowNmb--)
    {
        if(highNmb % 2)
        {
            result = pow(highNmb, stepen) + (double)lowNmb/result;
        }
        else
        {
            result = lowNmb + pow(highNmb, stepen)/result;
        }
        highNmb++;
        if(stepen == 1)
            stepen = n/2;
        else
            stepen--;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, 2*n-1, 1, n));
    printf("%lf", iterativna(n));
    return 0;
}
