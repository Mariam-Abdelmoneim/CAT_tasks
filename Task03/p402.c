#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pow, base,res = 1;

    printf("Base number? ");
    scanf("%d", &base);

    printf("Power? ");
    scanf("%d",&pow);

    for (int i =1 ; i <= pow; i++)
    {
        res *= base;
    }
    printf("Answer = %d\n", res);
}