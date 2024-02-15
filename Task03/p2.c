#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    int flag = 0;
    printf("Enter year: ");
    scanf("%d",&year);

    if((year%4 == 0 && year%100 != 0)||year%400==0)
        printf("LEAP Year!\n");
    else
        printf("NOT LEAP Year!\n");
}