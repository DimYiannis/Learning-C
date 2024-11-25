#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    char name[50];
    int salary;
};

void reademploydetails(struct employee *emp)
{
    printf("\n Enter your id: \n");
    scanf("%d", &(*emp).id);
    printf("\n Enter your name: \n");
    scanf("%s", emp->name);
    printf("\n Enter your salary: \n");
    scanf("%d", &emp->salary);
}

struct employee findhighestsalaryemployee(struct employee emp1, struct employee emp2, struct employee emp3)
{
    if (emp1.salary >= emp2.salary && emp1.salary >= emp3.salary)
    {
        return emp1;
    }
    else if (emp2.salary >= emp1.salary && emp2.salary >= emp3.salary)
    {
        return emp2;
    }
    else
    {
        return emp3;
    }
}

int main()
{

    struct employee emp1, emp2, emp3;

    reademploydetails(&emp1);
    reademploydetails(&emp2);
    reademploydetails(&emp3);

    struct employee highestSalaryEmployee;
    highestSalaryEmployee = findhighestsalaryemployee(emp1,emp2,emp3);

    printf("\n the highest salary employee is: %s with salary : %d, and id number: %d", highestSalaryEmployee.name, highestSalaryEmployee.salary, highestSalaryEmployee.id);
}