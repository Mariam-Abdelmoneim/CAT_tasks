#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0, i;
    long n;

    printf("Enter any number to find sum of its digits: ");
    scanf("%ld",&n);

    while (n != 0)
    {
        i = n % 10;
        sum += i;
        n/=10;
    }
    
    printf("Sum of digits: %d\n", sum);

}