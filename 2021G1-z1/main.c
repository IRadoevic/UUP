#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rekurzivna(int left, int right, int iteration, int n, int f)
{
    if(iteration == n)
    {
        return pow(left, iteration) + right;
    }
    int newRight;
    if(iteration <= n/2)
    {
        newRight = right - 1;
    }
    else if(iteration == n/2 + 1 && n%2)
    {
        newRight = right - 1;
    }
    else if(iteration == n/2 + 1)
    {

    }
    else
    {
        newRight = right + 1;
    }
    if(f)
    {
        return pow(left, iteration) + (double)right/rekurzivna(left - iteration*2, newRight, iteration + 1, n, 0);
    }
    return left + pow(right, iteration)/rekurzivna(left - iteration*2, newRight, iteration + 1, n, 1);

}

double iterativna(int n)
{
    int left = n * (9 - n);
    int right = n, stepen = n;
    double result = pow(left, stepen) + right;
    for(int iteration = 1; iteration <= n - 1; iteration++)
    {
        stepen--;
        left += (n - iteration)*2;
        if(iteration > n/2)
        {
            right++;
        }
        else if(iteration == (n/2 - 1) && n % 2)
        {
            right--;
        }
        else if(iteration == (n/2 - 1))
        {

        }
        else
        {
            right--;
        }
        if(iteration % 2)
        {
            result = left + pow(right, stepen)/result;
        }
        else
        {
            result = pow(left, stepen) + (double)right/result;
        }
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    int f = 0;
    if(n % 2)
    {
        f = 1;
    }
    printf("%lf\n", rekurzivna(n*8, n, 1, n, f));
    printf("%lf", iterativna(n));
    return 0;
}
