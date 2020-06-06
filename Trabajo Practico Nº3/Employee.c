#include <stdlib.h>
#include "Employee.h"
#include "Inputs.h"
#include <string.h>
#include <stdio.h>


Employee* employee_new()
{
    Employee* employee;

    employee=(Employee*)malloc(sizeof(Employee));
    if(employee == NULL)
    {
        printf("ERROR\n");
    }

    return employee;
}
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr,char* salaryStr )
{
    Employee* employee;
    int auxInt;
    float auxFloat;



    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && salaryStr!=NULL)
    {
        employee=(Employee*)malloc(sizeof(Employee));
        if(employee != NULL)
        {
            auxInt=atoi(idStr);
            employee_setId(employee, auxInt);
            employee_setNombre(employee, nameStr);
            auxInt=atoi(hoursWorkedStr);
            employee->hoursWorked=auxInt;
            employee_setHoursWorked(employee, auxInt);
            auxFloat=atof(salaryStr);
            employee_setSueldo(employee, auxFloat);
        }
    }


    return employee;
}
int employee_delete(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int ret=-1;
    Employee* employee;
    char confirmation[100];

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id= GetUnsignedInt("Ingrese ID a buscar: ", "ERROR! Igrese ID a buscar: ");
        index= employee_FindById(pArrayListEmployee, id);
        if(index!=-1)
        {
            employee=ll_get(pArrayListEmployee, index);
            employee_PrintOneEmployee(employee);

            getString(confirmation, "Desea realmente eliminar este empleado?: ", "ERROR! Desea realmente eliminar este empleado?: ");
            if(stricmp(confirmation, "si")==0)
            {
                ret=1;
                ll_remove(pArrayListEmployee, index);
            }else{
                ret=0;
            }
        }
    }


    return ret;
}
int employee_PrintOneEmployee(Employee* employee)
{
    int id;
    char name[100];
    int hoursWorked;
    float salary;

    if(employee!=NULL)
    {
        employee_getId(employee, &id);
        employee_getNombre(employee, &name);
        employee_getHorasTrabajadas(employee, &hoursWorked);
        employee_getSueldo(employee, &salary);

        printf("%10d %20s %10d %10.2f\n", id, name, hoursWorked, salary);

    }


}

int employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* aux;
    int auxId;
    int i;
    int index=-1;
    int size=ll_len(pArrayListEmployee);

    for(i=0; i<size; i++)
    {
        aux=ll_get(pArrayListEmployee, i);
        employee_getId(aux, &auxId);

        if(id == auxId){
            index=i;
            break;
        }
    }
    return index;

}

int employee_setNombre(Employee* employee,char* name)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        strcpy(employee->name, name);
    }
    return ret;
}

int employee_getNombre(Employee* employee,char* name)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        strcpy(name,employee->name);
    }
    return ret;
}



int employee_setSueldo(Employee* employee,float sueldo)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        employee->salary=sueldo;
    }
    return ret;

}
int employee_getSueldo(Employee* employee,float* sueldo)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        *sueldo=employee->salary;
    }
    return ret;

}

int employee_setId(Employee* employee,int id)
{
    int ret=0;

    if(employee !=NULL )
    {
        ret=1;
        employee->id=id;

    }
    return ret;

}
int employee_getId(Employee* employee,int* id)
{
    int ret=0;

    if(employee !=NULL )
    {
        ret=1;
        *id=employee->id;
    }
    return ret;
}

int employee_setHoursWorked(Employee* employee,int hoursWorked)
{
    int ret=0;

    if(employee !=NULL )
    {
        ret=1;
        employee->hoursWorked=hoursWorked;
    }
    return ret;
}
int employee_getHorasTrabajadas(Employee* employee,int* hoursWorked)
{
    int ret=0;

    if(employee !=NULL )
    {
        ret=1;
        *hoursWorked=employee->hoursWorked;
    }
    return ret;

}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad


    return strcmp(e1->name, e2->name);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return strcmp(e1->name, e2->name);
}




