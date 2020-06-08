#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char idStr[100];
    char nameStr[100];
    char salaryStr[100];
    char hoursStr[100];
    char cabecera[100];
    int i=-1;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do{
            i++;
            if(i==0){
                fscanf(pFile, "%[^\n]\n",cabecera);
                printf("cabecera:%s\n", cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr,nameStr,hoursStr,salaryStr);
            auxEmployee=employee_newParametros(idStr, nameStr, hoursStr,salaryStr);
            ll_add(pArrayListEmployee,auxEmployee);
        }while(!feof(pFile));

        fclose(pFile);

    }
    controller_ListEmployee(pArrayListEmployee);



    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employee;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            employee=employee_new();
            if(employee!=NULL)
            {
                fread(employee,sizeof(Employee),1,pFile);
                ll_add(pArrayListEmployee,employee);
            }
        }
        fclose(pFile);
    }
    controller_ListEmployee(pArrayListEmployee);

    return 1;
}
