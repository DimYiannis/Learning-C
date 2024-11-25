#include <stdio.h>
#include <stdlib.h>


int main()
{
    //This declares an array of characters (line) that can hold up to 255 characters. It's used to store the content of each line read from the file.
    char line[255];

    //This line opens a file named "employees.txt" in read-only mode ("r"), and it associates a file pointer (fpointer) with that file.
    FILE * fpointer = fopen("employees.txt", "r");
    
    fgets(line, 255, fpointer);
    fgets(line, 255, fpointer);
    printf("%s", line);

    fclose(fpointer);
    return 0;
}
