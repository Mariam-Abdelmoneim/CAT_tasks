#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nZeros = 0, nOnes = 0;
    int num;
    int size = 8 * sizeof(int);

    printf("Enter any Number: ");
    scanf("%d", &num);

    for (int i = 0; i < size; i++)
    {
        if (num & 1)
            nOnes++;
        else
            nZeros++;

        num>>=1;
    }
    printf("Total Zero bits -> %d\n", nZeros);
    printf("Total One bits -> %d\n", nOnes);
}