#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "Inputs.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myTextFile;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myTextFile=fopen(path, "r");
        if(myTextFile!=NULL)
        {
            parser_EmployeeFromText(myTextFile, pArrayListEmployee);
        }else{
            printf("Archivo inexistente, se procederá a crear una carpeta\n");

            myTextFile=fopen(path, "w");
            if(myTextFile!=NULL)
            {
                printf("Carpeta creada\n");
            }else{
                printf("ERROR! No se ha podido crear carpeta\n");
            }

        }
    }else{
        printf("ERROR\n");
    }


    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myBinaryFile;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myBinaryFile=fopen(path, "rb");
        if(myBinaryFile!=NULL)
        {
            parser_EmployeeFromBinary(myBinaryFile, pArrayListEmployee);

        }else{
            printf("Archivo inexistente, se procederá a crear una carpeta\n");
            myBinaryFile=fopen(path, "wb");
            if(myBinaryFile!=NULL)
            {
                printf("Carpeta creada\n");
            }else{
                printf("ERROR! No se ha podido crear carpeta\n");
            }
        }
    }else{
        printf("ERROR\n");
    }
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;
    Employee* auxEmployee;
    int i;
    int size;
    int maxId;
    int id;
    char name[100];
    int hoursWorked;
    float salary;

    if(pArrayListEmployee != NULL)
    {
        employee=employee_new();
        if(employee != NULL)
        {
            /// crear funcion maxId
            size=ll_len(pArrayListEmployee);
            if(size==0){
                maxId=0;
            }else{
                for(i=0; i<size; i++)
                {
                    auxEmployee=ll_get(pArrayListEmployee, i);
                    employee_getId(auxEmployee, &id);

                    if(maxId < id || i==0){
                        maxId=id;
                    }
                }
            }

            id=GetId(maxId);
            printf("Su id es: %d\n", id);
            getString(name, "Ingrese nombre del empleado: ", "ERROR! Ingrese nombre del empleado: ");
            hoursWorked=GetInt("Ingrese horas trabajadas del empleado: ","ERROR! Ingrese horas trabajadas del empleado: ",60, 325);
            salary=GetFloat("Ingrese salario del empleado: ","ERROR! Ingrese salario del empleado: ",10000.0, 55000.0);

            employee_setId(employee, id);
            employee_setNombre(employee, name);
            employee_setHoursWorked(employee, hoursWorked);
            employee_setSueldo(employee, salary);

            ll_add(pArrayListEmployee, employee);
        }
    }else{
        printf("ERROR\n");
    }


    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret;

    if(pArrayListEmployee != NULL)
    {
    ret=employee_delete(pArrayListEmployee);
        switch(ret)
        {
            case 1:
                printf("Eliminado\n");
                break;
            case 0:
                printf("Accion cancelada\n");
                break;
            case -1:
                printf("No se encontro id\n");
                break;
        }
    }else{
        printf("ERROR\n");
    }
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int size;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            aux =ll_get(pArrayListEmployee, i);
            employee_PrintOneEmployee(aux);
        }
    }else{
        printf("ERROR\n");
    }

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int option;

    if(pArrayListEmployee != NULL)
    {
        option=GetInt("MENU DE ORDENAMIENTOS\n1.Ordenar por nombre alfabeticamente\n2.Ordenar por id\n3.Ordenar por salario\n4.Ordenar por horas trabajadas\nIngrese la opcion: ", "ERROR! reingrese la opcion: ",1,4);
        printf("Ordenando...\n");
        switch(option)
        {
            case 1:
                printf("Ordenando...");
                ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_CompareById, 1);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_CompareBySalary, 1);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_CompareByHoursWorked, 1);
                break;
        }




    }
    controller_ListEmployee(pArrayListEmployee);



    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myTextFile;
    Employee* employee;
    int i;
    int size;
    int id;
    char name[100];
    int hoursWorked;
    float salary;


    if(pArrayListEmployee != NULL && path != NULL)
    {
        myTextFile=fopen(path, "w");
        if(myTextFile!= NULL)
        {
            fprintf(myTextFile, "id,nombre,horasTrabajadas,sueldo\n");

            size=ll_len(pArrayListEmployee);
            for(i=0; i<size; i++)
            {
                employee=ll_get(pArrayListEmployee, i);
                employee_getId(employee, &id);
                employee_getNombre(employee, name);
                employee_getHorasTrabajadas(employee, &hoursWorked);
                employee_getSueldo(employee, &salary);

                fprintf(myTextFile, "%d,%s,%d,%.0f\n", id, name, hoursWorked, salary);
            }
        }
        fclose(myTextFile);
    }else{
        printf("ERROR\n");
    }
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* myBinaryFile;
    Employee* employee;
    int size;
    int i;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        myBinaryFile=fopen(path, "wb");
        if(myBinaryFile!=NULL)
        {
            size=ll_len(pArrayListEmployee);
            for(i=0; i<size; i++)
            {
                employee=ll_get(pArrayListEmployee, i);
                fwrite(employee, sizeof(Employee),1,myBinaryFile);
            }

            fclose(myBinaryFile);
        }
    }else{
        printf("ERROR\n");
    }

    return 1;
}

