#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* myList = ll_newLinkedList();
    int option;
    do
    {
        option=UserMenue();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",myList);
                break;
            case 2:
                controller_loadFromBinary("data.bin", myList);
                break;
            case 3:
                controller_addEmployee(myList);
                break;
            case 4:

                break;
            case 5:
                controller_removeEmployee(myList);
                break;
            case 6:
                controller_ListEmployee(myList);
                break;
            case 7:

                break;
            case 8:
                controller_saveAsText("data.csv",myList);
                break;
            case 9:
                controller_saveAsBinary("data.bin", myList);
                break;
            case 10:
                break;
        }
    system("pause");
    system("cls");
    }while(option!=10);


 /* Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
    */



    return 0;
}
