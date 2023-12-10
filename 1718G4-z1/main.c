#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int iteration, int left, int right, int n)
{
    if(iteration == n)
    {
        return left;
    }
    return left + (double)right/rekurzivna(iteration + 1, left + iteration, right - 11, n);
}

double iterativna(int n)
{
    int right = 21;
    int left = n + (double)((n-1)*n/2);
    double result = left;
    left -= n - 1;
    for(int iteration = n - 2; iteration >= 0; iteration--)
    {
        result = left + (double)right/result;
        left -= iteration;
        right += 11;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n, n*11-1, n));
    printf("%lf", iterativna(n));
    return 0;
}
