#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{   //declaracion variables
    int opcion;
    float numA, numB;
    int flagIngresoNumA=0;
    int flagIngresoNumB=0;
    int flagCaseTres=0;

    do{ //menu de opciones
        getMenuCalculadora(flagIngresoNumA, flagIngresoNumB,  numA, numB);
        opcion=getInt("Ingrese una opcion: ", "No es una opcion valida, vuelva a ingresar una opcion: ",1 , 5);

        switch(opcion)
        {   case 1://ingreso numeros
                numA=getFloat("Ingrese primer operando: ");
                flagIngresoNumA=1;
                break;
            case 2:
                numB=getFloat("Ingrese segundo operando: ");
                flagIngresoNumB=1;
                break;
            case 3://muestro operaciones
                flagCaseTres=mostrarCalculos(flagIngresoNumA, flagIngresoNumB, numA, numB);
                break;
            case 4://llamado a funcion que llama a las funciones para mostrar serultados
                obtenerResultadosOperaciones(flagCaseTres,numA, numB);
                break;
            case 5:
                break;
            default:
                printf("\nNo es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion!=5);
    return 0;
}





