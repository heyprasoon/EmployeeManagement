#include <stdio.h>

#include <stdlib.h>

#include <string.h>



// Define a struct for Date

struct Date

{

    int dd, mm, yy;

};



// Define the Employee structure with composition

struct Employee

{

    int Empno;

    char EmpName[50];

    struct Date hiredate;

    float BasicSalary;

};



// Function to accept employee data

void acceptEmployee(struct Employee *employee)

{

    printf("Enter Employee Number: ");

    scanf("%d", &employee->Empno);

   

    printf("Enter Employee Name: ");

    scanf("%s", employee->EmpName);

   

    printf("Enter Hire Date (dd mm yy): ");

    scanf("%d %d %d", &employee->hiredate.dd, &employee->hiredate.mm, &employee->hiredate.yy);

   

    printf("Enter Basic Salary: ");

    scanf("%f", &employee->BasicSalary);

}



// Function to calculate net pay

float calculateNetPay(float BasicSalary)

{

    // Constants for allowances and PF

    const float DA_PERCENTAGE = 40.0;

    const float TA_PERCENTAGE = 10.0;

    const float PF_PERCENTAGE = 5.0;



    // Calculate allowances and PF

    float DA = (DA_PERCENTAGE / 100) * BasicSalary;

    float TA = (TA_PERCENTAGE / 100) * BasicSalary;

    float PF = (PF_PERCENTAGE / 100) * BasicSalary;



    // Calculate net pay

    float netPay = BasicSalary + DA + TA - PF;



    return netPay;

}



// Function to display employee data including net salary

void showEmployee(struct Employee *employee)

{

    printf("\nEmployee Number: %d\n", employee->Empno);

    printf("Employee Name: %s\n", employee->EmpName);

    printf("Hire Date: %02d-%02d-%02d\n", employee->hiredate.dd, employee->hiredate.mm, employee->hiredate.yy);

    printf("Basic Salary: %.2f\n", employee->BasicSalary);



    // Calculate and display net salary

    float netPay = calculateNetPay(employee->BasicSalary);

    printf("Net Salary: %.2f\n", netPay);

}



int main()

{

    struct Employee emp;

   

    // Accept employee data

    acceptEmployee(&emp);

   

    // Display employee data

    showEmployee(&emp);

   

    return 0;

}
