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
    int flagMenu=0;
    char confirmation[100];
    do{
        option=UserMenue();
        system("cls");
        switch(option)
        {
            case 1:
                ret=controller_loadFromText("data.csv",myList);
                FunctionReturnMessagesWithDefault(&id,&flagMenu,ret,"","CARPETA CREADA EXITOSAMENTE!","ERROR AL CREAR LA CARPETA!","ERROR!(elemento nulo)","CARGA EXITOSA!");
                break;
            case 2:
                ret=controller_loadFromBinary("data.bin", myList);
                FunctionReturnMessagesWithDefault(&id,&flagMenu,ret,"","CARPETA CREADA EXITOSAMENTE!","ERROR AL CREAR LA CARPETA!","ERROR!(elemento nulo)","CARGA EXITOSA!");
                break;
            case 3:
                ret=controller_addEmployee(myList, &id, flagMenu);
                FunctionReturnMessages(ret," ", " ", "ERROR!(elemento NULL o no se leyo el archivo)","ALTA EXITOSA!");
                break;
            case 4:
                ret=controller_editEmployee(myList);
                FunctionReturnMessages(ret,"ACCION CANCELADA!", "NO SE ENCONTRO ID!", "ERROR!(elemento nulo o no hay empleados en la lista)","MODIFICACION EXITOSA!");
                break;
            case 5:
                ret=controller_removeEmployee(myList);
                FunctionReturnMessages(ret,"ACCION CANCELADA!", "NO SE ENCONTRO ID!", "ERROR!(elemento nulo o no hay empleados en la lista)","ELIMINACION EXITOSA!");
                break;
            case 6:
                ret=controller_ListEmployee(myList);
                FunctionReturnMessages(ret," ", "NO HAY EMPLEADOS EN LA LISTA", "ERROR!(elemento nulo o no hay empleados en la lista)","EMPLEADOS LISTADOS EXITOSAMENTE!");
                break;
            case 7:
                ret=controller_sortEmployee(myList);
                FunctionReturnMessages(ret," ", " ", "ERROR!(elemento nulo o no hay empleados en la lista)"," ");
                break;
            case 8:
                ret=controller_saveAsText("data.csv",myList);
                FunctionReturnMessages(ret," ", " ", "ERROR!(Elemento nulo o no hay empleados para cargar en el archivo)","SE HA GUARDADO EL ARCHIVO EXITOSAMENTE!");
                break;
            case 9:
                ret=controller_saveAsBinary("data.bin", myList);
                FunctionReturnMessages(ret," ", " ", "ERROR!(Elemento nulo o no hay empleados para cargar en el archivo)","SE HA GUARDADO EL ARCHIVO EXITOSAMENTE!");
                break;
            case 10:
                getString(confirmation,"Está seguro que desea salir?","ERROR! Está seguro que desea salir?");
                if(strcmpi(confirmation, "si")==0)
                {option=11;}
                break;
        }
    system("pause");
    system("cls");
    }while(option!=11);
    return 0;
}
