#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int main()
{
    int n, evens = 0, odds = 0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter %d elements of array: ",n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2==0)
            evens++;
        else odds++;
    }
    printf("Total even elements: %d\n", evens);
    printf("Total odd elements: %d\n",odds);


}