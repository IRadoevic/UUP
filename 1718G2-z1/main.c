#include <stdio.h>
#include <stdlib.h>

double rekurzivna(int lowLeft, int highLeft, int iteration, int right)
{
    if(right == 2)
    {
        if(iteration % 2)
        {
            return highLeft;
        }
        else
        {
            return lowLeft;
        }
    }
    if(iteration % 2)
    {
        return highLeft + (double)right/rekurzivna(lowLeft, highLeft - 1, iteration + 1, right - 2);
    }
    else
    {
        return lowLeft + (double)right/rekurzivna(lowLeft + 1, highLeft, iteration + 1, right - 2);
    }
}

double iterativna(int n)
{
    int lowLeft = n / 2;
    int highLeft = n / 2 + 1;
    int right = 4;
    double result;
    if(n % 2)
    {
        result = highLeft;
        highLeft++;
    }
    else
    {
        result = lowLeft;
        lowLeft--;
    }
    for(int iteration = n - 1; iteration > 0; iteration--)
    {
        if(iteration % 2)
        {
            result = highLeft + (double)right/result;
            highLeft++;
        }
        else
        {
            result = lowLeft + (double)right/result;
            lowLeft--;
        }
        right += 2;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, n, 1, 2*n));
    printf("%lf\n", iterativna(n));
    return 0;
}
