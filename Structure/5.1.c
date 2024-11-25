#include <stdio.h>
#include <stdlib.h>

#define NUM_EMPLOYEES 3

struct employee {
    int id;
    char name[50];
    int salary;
};

// Function to read employee details
void readEmployeeDetails(struct employee *emp) {
    printf("\n Enter your id: \n");
    scanf("%d", &emp->id);
    printf("\n Enter your name: \n");
    scanf(" %[^\n]%*c", emp->name);  // This will allow to input names with spaces
    printf("\n Enter your salary: \n");
    scanf("%d", &emp->salary);
}

// Function to find the employee with the highest salary
struct employee findHighestSalaryEmployee(struct employee employees[], int numEmployees) {
    struct employee highestSalaryEmployee = employees[0];
    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].salary > highestSalaryEmployee.salary) {
            highestSalaryEmployee = employees[i];
        }
    }
    return highestSalaryEmployee;
}

int main() {
    struct employee employees[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        readEmployeeDetails(&employees[i]);
    }

    struct employee highestSalaryEmployee = findHighestSalaryEmployee(employees, NUM_EMPLOYEES);

    printf("\n The highest salary employee is: %s with salary: %d, and id number: %d\n", highestSalaryEmployee.name, highestSalaryEmployee.salary, highestSalaryEmployee.id);

    return 0;
}

/*Key Improvements:
Array of Employees: Uses an array to store multiple employees.
Loop for Input: Uses a loop to read details of multiple employees.
Dynamic Function: The findHighestSalaryEmployee function can handle any number of employees based on the NUM_EMPLOYEES constant.
This approach makes the program more scalable and easier to adjust if the number of employees changes. You simply change the NUM_EMPLOYEES constant, and the rest of the code adjusts accordingly.*/