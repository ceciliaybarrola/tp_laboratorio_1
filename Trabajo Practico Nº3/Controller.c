#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "Inputs.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myTextFile;
    int ret=-1;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myTextFile=fopen(path, "r");
        if(myTextFile!=NULL)
        {
            ret=parser_EmployeeFromText(myTextFile, pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente, se procederá a crear una carpeta\n");
            myTextFile=fopen(path, "w");

            if(myTextFile!=NULL){
                ret=-2;
            }
        }
    }

    return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myBinaryFile;
    int ret=-1;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myBinaryFile=fopen(path, "rb");
        if(myBinaryFile!=NULL)
        {
            ret=parser_EmployeeFromBinary(myBinaryFile, pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente, se procederá a crear una carpeta\n");
            myBinaryFile=fopen(path, "wb");
            if(myBinaryFile!=NULL)
            {
                ret=-2;
            }
        }
    }


    return ret;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    Employee* employee;
    char name[100];
    int hoursWorked;
    float salary;
    int ret=0;

    if(pArrayListEmployee != NULL && id!=NULL)
    {
        employee=employee_new();
        if(employee != NULL)
        {
            *id=GetId(*id);
            printf("Su id es: %d\n", *id);
            getString(name, "Ingrese nombre del empleado: ", "ERROR! Ingrese nombre del empleado: ");
            hoursWorked=GetInt("Ingrese horas trabajadas del empleado: ","ERROR! Ingrese horas trabajadas del empleado: ",60, 325);
            salary=GetFloat("Ingrese salario del empleado: ","ERROR! Ingrese salario del empleado: ",10000.0, 55000.0);

            if(employee_setId(employee, *id)==1 &&
               employee_setName(employee, name)==1 &&
               employee_setHoursWorked(employee, hoursWorked)==1 &&
               employee_setSalary(employee, salary==1))
            {
                ll_add(pArrayListEmployee, employee);
                ret=1;
            }
        }
    }

    return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int id;
    int index;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=GetUnsignedInt("Ingrese ID a modificar: ", "ERROR! Ingrese ID a modificar: ");
        index=employee_FindById(pArrayListEmployee,id);
        if(index != -1)
        {
            ret=employee_edit(pArrayListEmployee, index);
        }
    }else{
        ret=0;
    }
    return ret;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int index;
    int id;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id= GetUnsignedInt("Ingrese ID a buscar: ", "ERROR! Igrese ID a buscar: ");
        index= employee_FindById(pArrayListEmployee, id);
        if(index!=-1)
        {
            ret=employee_delete(pArrayListEmployee, index);
        }
    }else{
        ret=0;
    }
    return ret;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int ret=0;
    int size;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        printf("__________________________________________________________\n");
        printf("|    ID    |       NOMBRE       |HORAS TRABAJO|  SALARIO |\n");
        for(i=0; i<size; i++)
        {
            aux =(Employee*)ll_get(pArrayListEmployee, i);
            employee_PrintOneEmployee(aux);
        }
            printf("|__________|____________________|_____________|__________|\n");
        ret=1;
    }
    return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int ret=0;
    LinkedList* auxList=ll_clone(pArrayListEmployee);

    if(pArrayListEmployee!= NULL && auxList != NULL)
    {
        ret=1;
        do
        {
            option=GetInt("MENU DE ORDENAMIENTOS\n1.Ordenar por nombre alfabeticamente\n2.Ordenar por id\n3.Ordenar por salario\n4.Ordenar por horas trabajadas\n5.EXIT\nIngrese la opcion: ", "ERROR! reingrese la opcion: ",1,5);
            switch(option)
            {
            case 1:
                printf("Ordenando...\n");
                ll_sort(auxList, employee_CompareByName, 1);
                break;
            case 2:
                printf("Ordenando...\n");
                ll_sort(auxList, employee_CompareById, 1);
                break;
            case 3:
                printf("Ordenando...\n");
                ll_sort(auxList, employee_CompareBySalary, 1);
                break;
            case 4:
                printf("Ordenando...\n");
                ll_sort(auxList, employee_CompareByHoursWorked, 1);
                break;
            }
            if(option!=5)
            {
                controller_ListEmployee(auxList);
            }
            system("pause");
            system("cls");

        }
        while(option!=5);
        ll_deleteLinkedList(auxList);
    }

    return ret;;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myTextFile;
    int ret=0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        myTextFile=fopen(path, "w");
        if(myTextFile!= NULL)
        {
            ret=parser_EmployeeToText(myTextFile, pArrayListEmployee);
        }
    }
    return ret;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myBinaryFile;
    int ret=0;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myBinaryFile=fopen(path, "wb");
        if(myBinaryFile!=NULL)
        {
            ret=parser_EmployeeToBinary(myBinaryFile, pArrayListEmployee);
        }
    }

    return ret;
}

