#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Controller.h"

typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    float salary;

}Employee;

Employee* employee_new();
Employee* employee_newParameters(char* idStr,char* nameStr,char* hoursWorkedStr,char* salaryStr);
int employee_delete(LinkedList* pArrayListEmployee, int index);
int employee_edit(LinkedList* pArrayListEmployee, int id);
int employee_FindById(LinkedList* pArrayListEmployee, int id);

int employee_PrintOneEmployee(Employee* employee);

int employee_setId(Employee* employee,int id);
int employee_getId(Employee* employee,int* id);

int employee_setName(Employee* employee,char* name);
int employee_getName(Employee* employee,char* name);

int employee_setHoursWorked(Employee* employee,int hoursWorked);
int employee_getHoursWorked(Employee* employee,int* hoursWorked);

int employee_setSalary(Employee* employee,float salary);
int employee_getSalary(Employee* employee,float* salary);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* employee1, void* employee2);
int employee_CompareBySalary(void* employee1, void* employee2);
int employee_CompareByHoursWorked(void* employee1, void* employee2);

#endif //employee_H_INCLUDED
