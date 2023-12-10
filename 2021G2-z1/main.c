#include <stdio.h>
#include <stdlib.h>

double rekurzivna(char lowLet, char highLet, int nmb, int iteration, int n)
{
    if(iteration == n)
    {
        if(n % 2)
        {
            return lowLet;
        }
        return highLet;
    }
    int newNmb;
    if(iteration < n/2)
    {
        newNmb = nmb - 1;
    }
    else if(iteration == n / 2 && n % 2)
    {

    }
    else
    {
        newNmb = nmb + 1;
    }
    if(iteration % 2)
    {
        return lowLet + (double)nmb/rekurzivna(lowLet + 1, highLet, newNmb, iteration + 1, n);
    }
    return highLet + (double)nmb/rekurzivna(lowLet, highLet - 1, newNmb, iteration + 1, n);
}

double iterativna(int n)
{
    char lowLet, highLet;
    double result;
    int nmb = n / 2;
    if(n % 2)
    {
        lowLet = 'A' + n/2;
        highLet = 'A' + n/2 + 1;
        result = lowLet;
        lowLet--;
    }
    else
    {
        lowLet = 'A' + n/2 - 1;
        highLet = 'A' + n/2;
        result = highLet;
        highLet++;
    }
    for(int i = 1; i < n; i++)
    {
        if(n % 2)
        {
            if(i % 2)
            {
                result = highLet + (double)nmb/result;
                highLet++;
            }
            else
            {
                result = lowLet + (double)nmb/result;
                lowLet--;
            }
        }
        else
        {
            if(i % 2 == 0)
            {
                result = highLet + (double)nmb/result;
                highLet++;
            }
            else
            {
                result = lowLet + (double)nmb/result;
                lowLet--;
            }
        }
        if(i < n/2)
        {
            nmb--;
        }
        else if(n % 2 && i == n/2)
        {

        }
        else
        {
            nmb++;
        }

    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna('A', 'A' + n - 1, n/2, 1, n));
    printf("%lf", iterativna(n));
    return 0;
}
