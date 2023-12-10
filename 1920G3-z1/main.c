#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int highNmb, int lowNmb, int stepen)
{
    if(lowNmb == 1)
    {
        if(highNmb % 2)
        {
            return sqrt(pow(highNmb, stepen)/lowNmb);
        }
        else
        {
            return sqrt(lowNmb/pow(highNmb, stepen));
        }
    }
    int noviStepen;
    if(stepen == 3)
        noviStepen = 1;
    else
        noviStepen = stepen + 1;
    if(highNmb % 2)
    {
        return sqrt(pow(highNmb, stepen)/lowNmb + rekurzivna(highNmb - 1, lowNmb - 1, noviStepen));
    }
    return sqrt(lowNmb/pow(highNmb, stepen) + rekurzivna(highNmb - 1, lowNmb - 1, noviStepen));
}

double iterativna(int n)
{
    int highNmb = n, lowNmb = 1, stepen;
    double result;
    if(n % 2)
    {
        stepen = 1;
        result = sqrt(pow(highNmb, stepen)/lowNmb);
        lowNmb++;
        highNmb++;
    }
    else
    {
        stepen = n/2;
        result = lowNmb/pow(highNmb, stepen);
        lowNmb++;
        highNmb++;
    }
    for(lowNmb = 2; lowNmb <= n; lowNmb++)
    {
        if(stepen == 1)
        {
            stepen = n/2;
        }
        else
        {
            stepen--;
        }
        if(highNmb % 2)
        {
            result = sqrt(pow(highNmb, stepen)/lowNmb + result);
        }
        else
        {
            result = sqrt(lowNmb/pow(highNmb, stepen) + result);
        }
        highNmb++;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(2*n-1, n, 1));
    printf("%lf", iterativna(n));
    return 0;
}
