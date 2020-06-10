#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"

int main()
{
    LinkedList* myList = ll_newLinkedList();
    int id=0;
    int ret;
    int option;
    do{
        option=UserMenue();
        system("cls");
        switch(option)
        {
            case 1:
                ret=controller_loadFromText("data.csv",myList);
                switch(ret){
                    case -2:
                        printf("CARPETA CREADA EXITOSAMENTE!\n");
                        break;
                    case -1:
                        printf("ERROR AL CREAR LA CARPETA!\n");
                        break;
                    case 0:
                        printf("ERROR!\n");
                        break;
                    default:
                        printf("CARGA EXITOSA!\n");
                        id=ret;
                        break;
                }
                break;
            case 2:
                ret=controller_loadFromBinary("data.bin", myList);
                switch(ret){
                    case -2:
                        printf("CARPETA CREADA EXITOSAMENTE!\n");
                        break;
                    case -1:
                        printf("ERROR AL CREAR LA CARPETA!\n");
                        break;
                    case 0:
                        printf("ERROR!\n");
                        break;
                    default:
                        printf("CARGA EXITOSA!\n");
                        id=ret;
                }
                break;
            case 3:
                ret=controller_addEmployee(myList, &id);
                switch(ret){
                    case 0:
                        printf("ERROR!\n");
                        break;
                    case 1:
                        printf("ALTA EXITOSA!\n");
                }
                break;
            case 4:
                ret=controller_editEmployee(myList);
                switch(ret){
                    case 0:
                        printf("ERROR!\n");
                        break;
                    case 1:
                        printf("MODIFICACION EXITOSA!\n");
                        break;
                    case -1:
                        printf("NO SE ENCONTRO ID!\n");
                        break;
                    case -2:
                        printf("ACCION CANCELADA!\n");
                        break;
                }
                break;
            case 5:
                ret=controller_removeEmployee(myList);
                switch(ret){
                    case 0:
                        printf("ERROR!\n");
                        break;
                    case 1:
                        printf("MODIFICACION EXITOSA!\n");
                        break;
                    case -1:
                        printf("NO SE ENCONTRO ID!\n");
                        break;
                    case -2:
                        printf("ACCION CANCELADA!\n");
                        break;
                }
                break;
            case 6:
                ret=controller_ListEmployee(myList);
                if(ret==0){
                    printf("ERROR!\n");
                }
                break;
            case 7:
                ret=controller_sortEmployee(myList);
                if(ret==0){
                    printf("ERROR!\n");
                }
                break;
            case 8:
                ret=controller_saveAsText("data.csv",myList);
                switch(ret){
                    case 0:
                        printf("ERROR!\n");
                        break;
                    case 1:
                        printf("SE HA GUARDADO EL ARCHIVO EXITOSAMENTE!\n");
                        break;
                }
                break;
            case 9:
                ret=controller_saveAsBinary("data.bin", myList);
                switch(ret){
                    case 0:
                        printf("ERROR!\n");
                        break;
                    case 1:
                        printf("SE HA GUARDADO EL ARCHIVO EXITOSAMENTE!\n");
                        break;
                }
                break;
            case 10:
                break;
        }
    system("pause");
    system("cls");
    }while(option!=10);

    return 0;
}


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



