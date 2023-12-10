#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
double rekurzivna(int iteration, int n)
{
    if(iteration == n)
        return 1;
    return sqrt((n - iteration + 1)*(n - iteration + 1) + nthFibo(iteration + 1) * rekurzivna(iteration + 1, n));
}

double iterativna(int n)
{
    double result = 1;
    for(int i = 2; i <= n; i++)
    {
        result = sqrt(i*i + nthFibo(n - i + 2) * result);
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n));
    printf("%lf", iterativna(n));
    return 0;
}
