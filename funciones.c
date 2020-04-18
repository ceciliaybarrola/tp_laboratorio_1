#include "funciones.h"
#include <stdio.h>
void getMenuCalculadora(int flagA, int flagB, float numA, float numB)
{
    printf("\n----------CALCULADORA----------\n");
    //muestro variables de menu segun los datos que se hayan obtenidos
    if(flagA==1 && flagB==1)
    {
        printf("\n1. Ingresar primer operando:A=%.2f", numA);
        printf("\n2. Ingresar segundo operando:B=%.2f", numB);
        printf("\n3. Calculos\n a) Calcular suma (A+B)\n b) Calcular resta (A-B)\n c) Calcular multiplicacion (A*B)\n d) Calcular division (A/B)\n e) Calcular factorial(A!,B!)\n4. Informar resultados\n5. Salir\n");
        return;
    }
    if(flagA==1 && flagB==0)
    {
        printf("\n1. Ingresar primer operando:A=%.2f", numA);
        printf("\n2. Ingresar segundo operando:B=Y");
        printf("\n3. Calculos\n a) Calcular suma (A+B)\n b) Calcular resta (A-B)\n c) Calcular multiplicacion (A*B)\n d) Calcular division (A/B)\n e) Calcular factorial(A!,B!)\n4. Informar resultados\n5. Salir\n");
        return;
    }
    if(flagA==0 && flagB==1)
    {
        printf("\n1. Ingresar primer operando:A=X");
        printf("\n2. Ingresar segundo operando:B=%.2f",numB);
        printf("\n3. Calculos\n a) Calcular suma (A+B)\n b) Calcular resta (A-B)\n c) Calcular multiplicacion (A*B)\n d) Calcular division (A/B)\n e) Calcular factorial(A!,B!)\n4. Informar resultados\n5. Salir\n");
        return;
    }
    if(flagA==0 && flagB==0)
    {
        printf("\n1. Ingresar primer operando:A=X");
        printf("\n2. Ingresar segundo operando:B=Y");
        printf("\n3. Calculos\n a) Calcular suma (A+B)\n b) Calcular resta (A-B)\n c) Calcular multiplicacion (A*B)\n d) Calcular division (A/B)\n e) Calcular factorial(A!,B!)\n4. Informar resultados\n5. Salir\n");
    }
}
int getInt(char mensaje[], char mensajeError[], int min, int max)
{
    int valorEntero;
    printf("%s", mensaje);
    scanf("%d", &valorEntero);


    while(valorEntero < min ||valorEntero > max)
    {
        printf("%s", mensajeError);
        scanf("%d", &valorEntero);
    }
    return valorEntero;

}

float getFloat(char mensaje[])
{
    float valorFlotante;
    printf("%s", mensaje);
    scanf("%f", &valorFlotante);


    return valorFlotante;
}

int mostrarCalculos(int flagIngresoNumB, int flagIngresoNumA, float numA, float numB)
{
    int flag=0;
    if (flagIngresoNumB==1 && flagIngresoNumA==1)
    {
        flag=1;

        printf("\n%.2f + %.2f",numA, numB);
        printf("\n%.2f - %.2f",numA, numB);
        printf("\n%.2f * %.2f",numA, numB);
        printf("\n%.2f / %.2f",numA, numB);
        printf("\n%.0f! , %.0f!\n",numA, numB);
    }
    else
    {
        printf("\nFalta ingresar un operando \n");
    }
    return flag;
}
void obtenerResultadosOperaciones(int flagCaseTres,float numA, float numB)
{
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    unsigned long int resultadoFactorialA;
    unsigned long int resultadoFactorialB;
    int NumAEsEntero;
    int NumBEsEntero;

    if (flagCaseTres==1){
        resultadoSuma= getSuma(numA,numB);
        resultadoResta= getResta(numA, numB);
        resultadoMultiplicacion=getMultiplicacion(numA, numB);
        printf("\nEl resultado de %.2f + %.2f es %.2f",numA, numB, resultadoSuma);
        printf("\nEl resultado de %.2f - %.2f es %.2f ",numA, numB, resultadoResta);
        printf("\nEl resultado de %.2f * %.2f es %.2f ",numA, numB, resultadoMultiplicacion);

        //validaciones, llamado a funciones para dividir y sacar el factorial y muestro mensajes de error o de resultados
        NumAEsEntero=getValidacionEsNatural(numA);
        NumBEsEntero=getValidacionEsNatural(numB);

        if (numB!=0){
           resultadoDivision=getDivision(numA, numB);
           printf("\nEl resultado de %.2f / %.2f es %.2f ",numA, numB, resultadoDivision);
        }
        else{
            printf("\nNo se puede dividir por 0");
        }

        if(NumAEsEntero==1){
            resultadoFactorialA=getFactorial(numA);
            printf("\nEl factorial de %.0f es %lu ",numA, resultadoFactorialA);
        }
        else{
            printf("\nNo se puede realizar factorial de %.2f (es negativo y/o decimal)",numA);
        }

        if (NumBEsEntero==1){
            resultadoFactorialB=getFactorial(numB);
            printf("\nEl factorial de %.0f es %lu \n",numB, resultadoFactorialB);
        }
        else{
            printf("\nNo se puede realizar factorial de %.2f (es negativo y/o decimal)\n",numB);
        }
    }
    else{
        printf("Por favor, ingrese primero al case tres\n");
    }

}
float getSuma(float numA,float numB)
{
    return numA+numB;
}

float getResta(float numA, float numB)
{
    return numA-numB;
}

float getMultiplicacion(float numA, float numB)
{
    return numA*numB;
}

float getDivision(float numA, float numB)
{
    return numA/numB;
}

unsigned long int getFactorial(float num)
{
    unsigned long int factorial=1;
    int i;
        for(i=num;i>0;i--)
        {
            factorial=factorial*(unsigned long int)i;
        }

    return factorial;
}

int getValidacionEsNatural(float num)
{
    int entero;
    int valorDeRetorno=1;
    entero=num;

    if(entero-num || num<0)
    {
        valorDeRetorno=0;
        return valorDeRetorno;
    }

        return valorDeRetorno;
}
