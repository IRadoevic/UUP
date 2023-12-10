#include <stdio.h>
#include <stdlib.h>

int nthFibo(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    int nmb1 = 1, nmb2 = 1, counter = 2;
    int tmp;
    while(counter != n)
    {
        tmp = nmb1 + nmb2;
        nmb1 = nmb2;
        nmb2 = tmp;
        counter++;
    }
    return nmb2;
}

double rekurzivna(char ch, int iteration, int n)
{
    if(iteration == n)
        return ch;

    char chNext;
    if(ch == 'a')
        chNext = 'a' + 3;
    else
        chNext = ch - 1;
    if(iteration % 2)
    {
        return ch + (double)nthFibo(iteration)/rekurzivna(chNext, iteration + 1, n);
    }
    return ch - (double)nthFibo(iteration)/rekurzivna(chNext, iteration + 1, n);
}

double iterativna(int n)
{
    char ch = 'a';
    double result = ch;
    ch++;
    for(int i = n - 1; i > 0; i--)
    {
        if(i % 2)
        {
            result = ch + (double)nthFibo(i)/result;
        }
        else
        {
            result = ch - (double)nthFibo(i)/result;
        }
        if(ch == 'd')
            ch = 'a';
        else
            ch++;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    char ch;
    if(n % 4 == 0)
        ch = 'd';
    else
        ch = 'a' + n%4 - 1;
    printf("%lf\n", rekurzivna(ch, 1, n));
    printf("%lf\n", iterativna(n));
    return 0;
}
