/*20. Write a program in C to show a pointer to an array
whose contents are pointers to structures.
Expected Output :

 Exmployee Name : Alex
 Employee ID :  1002
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char *name;
    int id;
};

int main()
{
    struct Employee emp1 = {'john', 1001}, emp2 = {"alex", 1002},
                    emp3 = {"nick", 1003};

    // Creating an array of pointers to struct employee
    struct Employee(*arr[]) = {&emp1, &emp2, &emp3};

    // Creating a pointer to an array of pointers to struct employee
    // pt stores the address of the array of pointers
    struct Employee(*(*pt)[3]) = &arr;

    printf(" Employee Name : %s \n", (**(*pt + 1)).name);
    
    /*Explanation for the printed employee name
printf("---------------- Explanation --------------------\n");
printf("(**(*pt+1)).empname\n");
printf("= (**(*&arr+1)).empname   as pt=&arr\n");
printf("= (**(arr+1)).empname     from rule *&pt = pt\n");
printf("= (*arr[1]).empname       from rule *(pt+i) = pt[i]\n");
printf("= (*&emp2).empname        as arr[1] = &emp2\n");
printf("= emp2.empname = Alex       from rule *&pt = pt\n\n");
*/
    printf(" Employee ID :  %d\n", (*(*pt + 1))->id);

    return 0;
}