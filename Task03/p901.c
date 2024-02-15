#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long binaryTodecimal(long bin_num);  
int main()
{
    long bin_num, dec_num; 
    
    printf("Enter a binary number: ");
    scanf("%ld", &bin_num);
      
    dec_num = binaryTodecimal (bin_num); 
    printf ("%ld in binary = %ld in decimal\n",bin_num, dec_num);  
    return 0;
}
long binaryTodecimal(long bin_num)  
{  
    long decimal_num = 0, temp = 0, rem;  
    while (bin_num != 0)  
    {  
        rem = bin_num % 10;  
        bin_num = bin_num / 10;  
        decimal_num = decimal_num + rem * pow( 2, temp);  
        temp++;  
    }  
    return decimal_num;  
}  