#include <stdio.h>
#include <stdlib.h>

void maximum(int*, int*);
void minimum(int*, int*);

int main()
{
    int a[4], mini, maxi;

    printf ("Enter 4 Numbers: ");
    for(int i = 0; i < 4; i++)
        scanf("%d",a+i);

    maximum(a,&maxi);
    minimum(a,&mini);
    printf("Max = %d\n", maxi);
    printf("Min = %d\n", mini);
}

void maximum(int *a, int *maxi )
{
    int maxi = *a;
    for(int i = 1; i < 4; i++)
    {
        if(*(a+i) > maxi)
            maxi = *(a+i);
    }
}
void minimum(int *a, int *mini)
{
    int mini = *a;
    for(int i = 1; i < 4; i++)
    {
        if(*(a+i) < mini)
            mini = *(a+i);
    }
}