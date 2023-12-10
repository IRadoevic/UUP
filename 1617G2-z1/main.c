#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(double a, int iteracija)
{
    if(a == 1)
    {
        if(iteracija % 2)
        {
            return sqrt(1)/a;
        }
        return sqrt(2)/a;
    }
    if(iteracija % 2)
    {
        return a + 1/rekurzivna(a-1, iteracija+1);
    }
    return a + sqrt(2)/rekurzivna(a-1, iteracija + 1);
}

double iterativna(int a)
{
    double rezultat;
    double k;
    if(a % 2)
    {
        k = 1.0;
    }
    else
    {
        k = 2.0;
    }
    rezultat = 1.0;
    for(int i = 2; i <= a; i++)
    {
        if(k == 1)
            k = 2;
        else
            k = 1;
        rezultat = i + sqrt(k)/rezultat;
        printf("%lf ", rezultat);
    }
    return rezultat;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(n, 1));
    printf("%lf", iterativna(n));
    return 0;
}
