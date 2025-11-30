#include <stdio.h>
#include <string.h>

struct Salary {
    float basic;
    float bonuses;
    float deductions;
};

struct Employee {
    int id;
    char name[50];
    struct Salary salary;
};

void calculateNetSalary(struct Employee e) {
    float net = e.salary.basic + e.salary.bonuses - e.salary.deductions;
    printf("\nEmployee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Pay: %.2f\n", e.salary.basic);
    printf("Bonuses: %.2f\n", e.salary.bonuses);
    printf("Deductions: %.2f\n", e.salary.deductions);
    printf("Net Salary: %.2f\n", net);
}

int main() {
    struct Employee emp;
    
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Basic Pay: ");
    scanf("%f", &emp.salary.basic);

    printf("Enter Bonuses: ");
    scanf("%f", &emp.salary.bonuses);

    printf("Enter Deductions: ");
    scanf("%f", &emp.salary.deductions);

    calculateNetSalary(emp);

    return 0;
}

