#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nthPrime(int n)
{
    if(n == 1)
        return 2;
    if(n == 2)
        return 3;
    int counter = 2;
    int i = 5;
    int flag = 1;
    while(counter != n)
    {
        flag = 1;
        for(int j = 2; j <= i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            counter++;
        i+=2;
    }
    return i-2;
}

double rekurzivna(char ch, int number, int n)
{
    if(number == n - 1)
    {
        return ch;
    }
    if(number % 2)
    {
        return ch + (double)nthPrime(number)/(rekurzivna(ch-1, number+1, n));
    }
    return ch - (double)nthPrime(number)/(rekurzivna(ch-1, number+1, n));
}

double iterativn(int n)
{
    char ch = 'A';
    double result = ch;
    ch++;
    for(int iteration = n; iteration > 0; iteration--)
    {
        if(iteration % 2)
        {
            result = ch + (double)nthPrime(iteration)/result;
        }
        else
        {
            result = ch - (double)nthPrime(iteration)/result;
        }
        ch++;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf", rekurzivna('A' + 6, 1, n));
    printf("\n%lf", iterativn(n));
    return 0;
}
