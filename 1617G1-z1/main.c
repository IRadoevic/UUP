#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int iteracija, double a)/** vrlo bitno da je a double!!!!!!!!!!!!*/
{
    if(a == 1)
    {
        if(iteracija%2)
        {
            return (1/a);
        }
        return (2/a);
    }
    if(iteracija%2)
    {
        return 1/a+sqrt(rekurzivna(iteracija+1, a-1));
    }
    return 2/a+sqrt(rekurzivna(iteracija+1, a-1));
}
double iterativna(int a)
{
    double rezultat;
    int k;
    if(a%2)
    {
        k = 1;
        rezultat = k/1;
    }
    else
    {
        k = 2;
        rezultat = k/1;
    }
    printf("\n%lf\n", rezultat);
    for(int i = 2; i <= a; i++)
    {
        if(k == 1)
        {
            k = 2;
        }
        else
        {
            k = 1;
        }
        rezultat = (double)k/i + sqrt(rezultat);/**opet vrlo bitno da kastuje*/
        printf("%lf ", rezultat);
    }
    return sqrt(rezultat);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", sqrt(rekurzivna(1, n)));
    printf("%lf", iterativna(n));
    return 0;
}
