
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
Employee* employee_newParameters(char* idStr,char* nameStr,char* hoursWorkedStr,char* salaryStr )
{
    Employee* employee;

    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && salaryStr!=NULL)
    {
        employee=employee_new();
        if(employee != NULL)
        {
            employee_setId(employee, atoi(idStr));
            employee_setName(employee, nameStr);
            employee_setHoursWorked(employee, atoi(hoursWorkedStr));
            employee_setSalary(employee, atof(salaryStr));
        }
    }else{
        printf("ERROR\n");
    }
    return employee;
}
int employee_delete(LinkedList* pArrayListEmployee, int index)
{
    int ret=-2;
    Employee* employee;
    Employee* employee1;
    char confirmation[100];

    if(pArrayListEmployee != NULL)
    {
            employee=(Employee*)ll_get(pArrayListEmployee, index);
            employee_PrintOneEmployee(employee);

            getString(confirmation, "Desea realmente eliminar este empleado?: ", "ERROR! Desea realmente eliminar este empleado?: ");
            if(stricmp(confirmation, "si")==0)
            {
                ret=1;
                employee1=ll_pop(pArrayListEmployee, index);
                printf("Se ha eliminado este empleado\n");
                employee_PrintOneEmployee(employee);
            }
    }else{
        ret=0;
    }
    return ret;
}
int employee_PrintOneEmployee(Employee* employee)
{
    int ret=0;
    int id;
    char name[100];
    int hoursWorked;
    float salary;

    if(employee!=NULL)
    {
        if(employee_getId(employee, &id)==1 && employee_getSalary(employee, &salary)==1 &&
           employee_getHoursWorked(employee, &hoursWorked)==1 &&employee_getName(employee, name)==1 )
        {
            printf("|%10d|%20s|%13d|%10.2f|\n", id, name, hoursWorked, salary);
            ret=1;
        }
    }

    return ret;
}

int employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListEmployee != NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(employee, &auxId);

            if(id == auxId){
                index=i;
                break;
            }
        }
    }
    return index;

}

int employee_setName(Employee* employee,char* name)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        strcpy(employee->name, name);
    }

    return ret;
}

int employee_getName(Employee* employee,char* name)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        strcpy(name,employee->name);
    }
    return ret;
}



int employee_setSalary(Employee* employee,float salary)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        employee->salary=salary;
    }
    return ret;

}
int employee_getSalary(Employee* employee,float* salary)
{
    int ret=0;
    if(employee !=NULL )
    {
        ret=1;
        *salary=employee->salary;
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
int employee_getHoursWorked(Employee* employee,int* hoursWorked)
{
    int ret=0;

    if(employee !=NULL )
    {
        ret=1;
        *hoursWorked=employee->hoursWorked;
    }
    return ret;

}


int employee_CompareByName(void* employee1, void* employee2)
{
    Employee* auxEmployee1;
    Employee* auxEmployee2;
    char name1[100];
    char name2[100];
    int ret=0;

    if(employee1 !=NULL && employee2 != NULL)
    {
        auxEmployee1=(Employee*)employee1;
        auxEmployee2=(Employee*)employee2;

        employee_getName(auxEmployee1, name1);
        employee_getName(auxEmployee2, name2);

        ret= stricmp(name1, name2);
    }
    return ret;

}
int employee_CompareBySalary(void* employee1, void* employee2)
{
    Employee* auxEmployee1;
    Employee* auxEmployee2;
    float salary1;
    float salary2;

    int ret=0;

    if(employee1 != NULL && employee2 != NULL)
    {
        auxEmployee1=(Employee*)employee1;
        auxEmployee2=(Employee*)employee2;

        employee_getSalary(auxEmployee1, &salary1);
        employee_getSalary(auxEmployee2, &salary2);

        if(salary1 > salary2)
        {
            ret=1;
        }
    }
    return ret;
}
int employee_CompareByHoursWorked(void* employee1, void* employee2)
{
    Employee* auxEmployee1;
    Employee* auxEmployee2;
    int hoursWorked1;
    int hoursWorked2;

    int ret=0;

    if(employee1 != NULL && employee2 != NULL)
    {
        auxEmployee1=(Employee*)employee1;
        auxEmployee2=(Employee*)employee2;

        employee_getHoursWorked(auxEmployee1, &hoursWorked1);
        employee_getHoursWorked(auxEmployee2, &hoursWorked2);

        if(hoursWorked1 > hoursWorked2)
        {
            ret=1;
        }
    }
    return ret;

}

int employee_CompareById(void* employee1, void* employee2)
{
    Employee* auxEmployee1;
    Employee* auxEmployee2;
    int id1;
    int id2;
    int ret;
    if(employee1 != NULL && employee2 != NULL)
    {
        auxEmployee1=(Employee*)employee1;
        auxEmployee2=(Employee*)employee2;

        employee_getId(auxEmployee1, &id1);
        employee_getId(auxEmployee2, &id2);

        if(id1 > id2)
        {
            ret=1;
        }
        if(id1 < id2){
            ret=0;
        }
    }
    return ret;
}
int employee_edit(LinkedList* pArrayListEmployee, int index)
{
    int ret=-2;
    int flag=0;
    int option;
    Employee* employee;
    char name[100];
    int hoursWorked;
    float salary;
    char confirmation[100];

    if(pArrayListEmployee != NULL)
    {
        employee=(Employee*)ll_get(pArrayListEmployee, index);
        if(employee!=NULL)
        {
            employee_getHoursWorked(employee, &hoursWorked);
            employee_getSalary(employee, &salary);
            employee_getName(employee, name);

            do{
                option=GetInt("MENU DE MODIFICACIONES\n1.Nombre\n2.Horas trabajadas\n3.Salario\n4.EXIT\nIngrese una opcion: ",
                               "ERROR! Ingrese una opcion: ",1 , 4);
                if(option!=4){
                    flag=1;
                }
                switch(option){
                    case 1:
                        getString(name, "Ingrese nuevo nombre: ","ERROR! Ingrese nuevo nombre: ");
                        break;
                    case 2:
                        hoursWorked=GetInt("Ingrese nuevas horas trabajadas del empleado: ","ERROR! Ingrese nuevas horas trabajadas del empleado: ",60, 325);
                        break;
                    case 3:
                        salary=GetFloat("Ingrese nuevo salario del empleado: ","ERROR! Ingrese nuevo salario del empleado: ",10000.0, 55000.0);
                        break;
                    case 4:
                        if(flag==1)
                        {
                            getString(confirmation, "Desea realmente modificar al empleado?: ", "ERROR! Desea realmente modificar al empleado?: ");
                            if(stricmp(confirmation, "si")==0)
                            {
                                ret=0;
                                if (employee_setName(employee, name)==1 && employee_setHoursWorked(employee, hoursWorked)==1 && employee_setSalary(employee, salary)==1){
                                    ret=1;
                                }
                            }
                        }
                        break;

                }
            system("pause");
            system("cls");

            }while(option != 4);
        }else{
            ret=0;
        }
    }
    return ret;
}




