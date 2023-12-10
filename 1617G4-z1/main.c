#include <stdio.h>
#include <stdlib.h>

double rekurzivna(int left, int right, int n)
{
    if(left == n)
        return left;
    if(left % 2)
    {
        return left+right/rekurzivna(left+1, right - 2, n);
    }
    return left-right/rekurzivna(left+1, right - 2, n);
}

double iterativna(int n)
{
    double rezultat = n;
    int right = 4;
    for(int left = n - 1; left > 0; left--)
    {
        if(left % 2)
        {
            rezultat = left + right/rezultat;
        }
        else
        {
            rezultat = left - right/rezultat;
        }
        right += 2;
    }
    return rezultat;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(1, 2*n, n));
    printf("%lf", iterativna(n));
    return 0;
}
