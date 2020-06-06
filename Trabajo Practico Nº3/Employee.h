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
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr,char* salaryStr);
int employee_delete(LinkedList* pArrayListEmployee);
int employee_FindById(LinkedList* pArrayListEmployee, int id);
int employee_PrintOneEmployee(Employee* employee);


int employee_setId(Employee* employee,int id);
int employee_getId(Employee* themployeeis,int* id);

int employee_setNombre(Employee* employee,char* name);
int employee_getNombre(Employee* employee,char* name);

int employee_setHoursWorked(Employee* employee,int hoursWorked);
int employee_getHorasTrabajadas(Employee* employee,int* hoursWorked);

int employee_setSueldo(Employee* employee,float sueldo);
int employee_getSueldo(Employee* employee,float* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

#endif //employee_H_INCLUDED
