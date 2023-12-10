#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(double iteracija, double drugiBroj, int n)
{
    if(iteracija == n)
    {
        return sqrt(iteracija*drugiBroj);
    }
    double drugiBrojTemp;
    if(drugiBroj == 1)
        drugiBrojTemp = n/2;
    else
        drugiBrojTemp = drugiBroj - 1;
    return sqrt(iteracija*drugiBroj + rekurzivna(iteracija + 1, drugiBrojTemp, n));
}

double iterativna(int n)
{
    double rezultat = n;
    int drugiBroj = 1;
    for(int i = n - 1; i > 0; i--)
    {
        if(drugiBroj == n/2)
            drugiBroj = 1;
        else
            drugiBroj++;
        rezultat = i*drugiBroj + sqrt(rezultat);
    }
    return sqrt(rezultat);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n/2, n));
    printf("%lf", iterativna(n));
    return 0;
}
