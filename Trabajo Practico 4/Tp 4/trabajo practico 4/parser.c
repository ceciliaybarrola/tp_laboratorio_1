
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int maxId=0;
    char idStr[100];
    char nameStr[100];
    char salaryStr[100];
    char hoursStr[100];
    char cabecera[100];
    int i=-1;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile)){
            i++;
            if(i==0){
                fscanf(pFile, "%[^\n]\n",cabecera);
                printf("cabecera: %s\n", cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr,nameStr,hoursStr,salaryStr);
            auxEmployee=employee_newParameters(idStr, nameStr, hoursStr,salaryStr);
            ll_add(pArrayListEmployee,auxEmployee);

            if(atoi(idStr)>maxId)///maxId se encuentra inicializada ya que sera usada como variable de retorno (los id tienen que ser positivos)
            {
                maxId=atoi(idStr);
            }

        }
        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);

    }
    return maxId;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int maxId=0;
    int id;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            if (feof(pFile)){
                break;
            }
            employee=employee_new();
            if(employee!=NULL)
            {
                if(fread(employee,sizeof(Employee),1,pFile)==1)
                {
                    ll_add(pArrayListEmployee,employee);
                    employee_getId(employee, &id);///maxId se encuentra inicializada ya que sera usada como variable de retorno (los id tienen que ser positivos)

                    if(id>maxId){
                        maxId=id;
                    }
                }
            }
        }
        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
    }


    return maxId;
}
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int size;
    int i;
    int ret=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            fwrite(employee, sizeof(Employee),1,pFile);
        }
        fclose(pFile);
        ret=1;
    }
    return ret;
}
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int i;
    int size;
    int id;
    char name[100];
    int hoursWorked;
    float salary;
    int ret=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(employee, &id)==1 && employee_getHoursWorked(employee, &hoursWorked)==1 &&
               employee_getName(employee, name)==1 && employee_getSalary(employee, &salary)==1)
            {
                ret=1;
                fprintf(pFile, "%d,%s,%d,%f\n", id, name, hoursWorked, salary);
            }
        }
        fclose(pFile);

    }
    return ret;
}
