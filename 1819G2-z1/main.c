#include <stdio.h>
#include <stdlib.h>

int nthFibo(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    int nmb1 = 1, nmb2 = 1;
    int cntr = 2, tmp;
    while(cntr != n)
    {
        tmp = nmb1 + nmb2;
        nmb1 = nmb2;
        nmb2 = tmp;
        cntr++;
    }
    return nmb2;
}

double rekurzivna(int iterator, int top, int n)
{
    if(iterator == n)
    {
        return nthFibo(iterator);
    }
    if(iterator % 2)
    {
        return nthFibo(iterator) + (double)top/rekurzivna(iterator + 1, top - 3, n);
    }
    return nthFibo(iterator) - (double)top/rekurzivna(iterator + 1, top - 3, n);
}

double iterativna(int n)
{
    double res = nthFibo(n);
    int top = 6;
    for(int i = n - 1; i > 0; i--)
    {
        if(i % 2)
        {
            res = nthFibo(i) + (double)top/res;
        }
        else
        {
            res = nthFibo(i) - (double)top/res;
        }
        top += 3;

    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n*3, n));
    printf("%lf", iterativna(n));
    return 0;
}
