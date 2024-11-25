#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    int salary;
};

// Function to read employee details
void readEmployeeDetails(struct employee *emp) {
    printf("\nEnter your id: ");
    scanf("%d", &emp->id);
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", emp->name);  // This will allow to input names with spaces
    printf("Enter your salary: ");
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
    struct employee *employees = NULL;
    int numEmployees = 0;
    char choice;

    do {
        employees = (struct employee *)realloc(employees, (numEmployees + 1) * sizeof(struct employee));
        if (employees == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        readEmployeeDetails(&employees[numEmployees]);
        numEmployees++;

        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    if (numEmployees > 0) {
        struct employee highestSalaryEmployee = findHighestSalaryEmployee(employees, numEmployees);
        printf("\nThe highest salary employee is: %s with salary: %d, and id number: %d\n", highestSalaryEmployee.name, highestSalaryEmployee.salary, highestSalaryEmployee.id);
    } else {
        printf("No employees were entered.\n");
    }

    free(employees);
    return 0;
}

/*Key Features:
Dynamic Memory Allocation: Uses realloc to dynamically adjust the size of the employee array.
User-Controlled Input: The user can keep entering employee data until they decide to stop.
Input Handling: Proper handling of strings with spaces and continuous input prompt.
Memory Management: Ensures allocated memory is freed at the end to avoid memory leaks.
This approach ensures that the program can handle an arbitrary number of employees, only limited by system memory.*/