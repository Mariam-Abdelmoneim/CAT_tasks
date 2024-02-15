#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    float n1, n2, res;

    printf("Enter an operator: ");
    scanf("%c", &op);

    printf("Enter Two Operands: ");
    scanf("%f %f", &n1, &n2);

    switch(op)
    {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            res = n1 / n2;
            break;
        default:
            printf("Invalid!\n");
    }
    printf("%0.1f %c %0.1f = %0.1f\n",n1,op,n2,res);
}