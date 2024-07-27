#include <stdio.h>

int main(){
    float salary, GS, FS;
    printf("Enter the salary of the employee: ");
    scanf("%f", &salary);
    GS = (salary / 100) * 60;
    FS = GS + salary;
    printf("The gross salary of the employee is: %f\n", FS);
    return 0;
}
