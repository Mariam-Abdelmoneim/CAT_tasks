#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    int salary;
    int bonus;
    int deductions;
}Employee;


int main()
{
    int total =0;
    printf("<-- Information for (MOHSEN): -->\n");
    Employee Mohsen;
    printf("Salary: ");
    scanf("%d",&(Mohsen.salary));
    printf("Bonus: ");
    scanf("%d",&(Mohsen.bonus));
    printf("Deductions: ");
    scanf("%d",&(Mohsen.deductions));

    printf("<-- Information for (MAGED): -->\n");
    Employee Maged;
    printf("Salary: ");
    scanf("%d",&(Maged.salary));
    printf("Bonus: ");
    scanf("%d",&(Maged.bonus));
    printf("Deductions: ");
    scanf("%d",&(Maged.deductions));

    printf("<-- Information for (MARIAM): -->\n");
    Employee Mariam;
    printf("Salary: ");
    scanf("%d",&(Mariam.salary));
    printf("Bonus: ");
    scanf("%d",&(Mariam.bonus));
    printf("Deductions: ");
    scanf("%d",&(Mariam.deductions));

    total = Mariam.salary + Mohsen.salary + Maged.salary + Mariam.bonus + Mohsen.bonus + Maged.bonus - Mariam.deductions - Mohsen.deductions - Maged.deductions;

    printf("\n\t>> Total Supplied Finance: %d\n", total);
}

