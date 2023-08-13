#include <stdio.h>
#include <stdlib.h>

struct Information
{
    int emp_Id;
    char name[50], designation[50];
    float basic_salary, hra_pct, da_pct;
};

int main()
{
    int n, i;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    getchar();

    struct Information emp[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter Employee %d information\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].emp_Id);
        printf("Employee Name: ");
        scanf("%s", emp[i].name);
        printf("Employee Designation: ");
        scanf("%s", emp[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA Percent: ");
        scanf("%f", &emp[i].hra_pct);
        printf("DA Percent: ");
        scanf("%f", &emp[i].da_pct);
    }

    printf("\nEmployee Information with Gross Salary:\n");
    for (i = 0; i < n; i++)
    {
        float hraAmt = emp[i].basic_salary * (emp[i].hra_pct / 100);
        float daAmt = emp[i].basic_salary * (emp[i].da_pct / 100);
        float grossSalary = emp[i].basic_salary + hraAmt + daAmt;

        printf("\nEmployee ID: %d\n", emp[i].emp_Id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA Amount: %.2f\n", hraAmt);
        printf("DA Amount: %.2f\n", daAmt);
        printf("Gross Salary: %.2f\n", grossSalary);
    }

    return 0;
}