#include <stdio.h>
#include <stdlib.h>

int maximum(int[]);
int minimum(int[]);

int main()
{
    int a[4];

    printf ("Enter 4 Numbers: ");
    for(int i = 0; i < 4; i++)
        scanf("%d",&a[i]);

    printf("Max = %d\n", maximum(a));
    printf("Min = %d\n", minimum(a));
}

int maximum(int a[])
{
    int m = a[0];
    for(int i = 1; i < 4; i++)
    {
        if(a[i] > m)
            m = a[i];
    }
    return m;
}
int minimum(int a[])
{
    int m = a[0];
    for(int i = 1; i < 4; i++)
    {
        if(a[i] < m)
            m = a[i];
    }
    return m;
}