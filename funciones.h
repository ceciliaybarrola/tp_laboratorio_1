#include <stdio.h>
/** \brief Obtiene dos numeros de otra funcion y realiza sumas
 *
 * \param numA float 1º Sumando
 * \param numB float 2º Sumando
 * \return float Retorna resultado de la Suma
 *
 */
float getSuma(float numA,float numB);

/** \brief Obtiene dos numeros de otra funcion y realiza restas
 *
 * \param numA float Minuendo
 * \param numB float Sustraendo
 * \return float Retorna diferencia
 *
 */
float getResta(float numA, float numB);

/** \brief Obtiene dos numeros de otra funcion y realiza multiplicaciones
 *
 * \param numA float    1º factor
 * \param numB float    2º factor
 * \return float    Restorna resultado de la multiplicacion
 *
 */
float getMultiplicacion(float numA, float numB);

/** \brief Obtiene dos numeros de otra fucnion y realiza divisiones
 *
 * \param numA float    Dividendo
 * \param numB float    Divisor
 * \return float    Devuelve resultado de division
 *
 */
float getDivision(float numA, float numB);

/** \brief Obtiene un numero y valida si es un numero natural
 *
 * \param num float    Recibe un numero flotante al cual se le otorga su valor a una variable entera para que se comparen entre si
 * \return int    Devuelve "0" o "1" dependiendo si la condicion es verdadera o falsa
 *
 */
int getValidacionEsNatural(float num);

/** \brief Recibe un numero y calcula el factorial con una iteracion for
 *
 * \param num float    Numero al cual se le aplica la operacion para conseguir el factorial
 * \return long long int    Retorna el factorial en long long int
 *
 */
unsigned long int getFactorial(float num);

/** \brief Funcion encargada de pedir un numero y devolverlo
 *
 * \param mensaje[] char    Mensaje que le indica al usuario que debe ingresar un numero
 * \return float    Devuelve un numero flotante
 *
 */
float getFloat(char mensaje[]);

/** \brief Funcion para obtener una opcion con un numero entero validado en un rango de numeros
 *
 * \param mensaje[] char    Mensaje que indica al usuario que ingrese un numero
 * \param mensajeError[] char   Mensaje de error indicandole al usuario que reingrese un numero valido
 * \param min int   Valor minimo del rango numerico
 * \param max int   Valor maximo del rango numerico
 * \return int  Devuelve opcion validada
 *
 */
int getInt(char mensaje[], char mensajeError[], int min, int max);

/** \brief Funcion para obtener un menu en el cual se pueden ver los operandos ingresados
 *
 * \param flagA     int Flag para que una funcion if sepa si mostrar en el menu el numero A o todavia no se ingreso
 * \param flagB    int Flag para que una funcion if sepa si mostrar en el menu el numero B o todavia no se ingreso
 * \param numA     float Primer operando ingresado por el usuario (tipo flotante)
 * \param numB     float Segundo operando ingresado por el usuario (tipo flotante)
 * \return void     No retorna un valor, solo muestra el menu
 *
 */
void getMenuCalculadora(int flagA, int flagB, float numA, float numB);

/** \brief Funcion Encargada de mostrar todos las operaciones a realizar y como quedarian los numeros ingresados
 *
 * \param flagIngresoNumB int   Flag utilizada para validar si el numero B se ingreso para que a la hora de ejecutar esta funcion no muestre basura en el lugar de esta variable
 * \param flagIngresoNumA int   Flag utilizada para validar si el numero A se ingreso para que a la hora de ejecutar esta funcion no muestre basura en el lugar de esta variable
 * \param numA float    Primer numero que se muestra, el valor lo obtiene de otra funcion
 * \param numB float    Segundo numero que se muestra, el valor lo obtiene de otra funcion
 * \return void    Devuelve un valor en "0" o "1" segun se haya podido mostrar los calculos, este dato se usara para en el case 4
 *
 */
int mostrarCalculos(int flagIngresoNumB, int flagIngresoNumA, float numA, float numB);


/** \brief Funcion encargada de obtener los resultados de las operaciones y mostrarlos
 *
 * \param flagCaseTres int  Flag que valida que se haya ingresado al menos una vez el case 3 para no mostrar resultados u operandos basura
 * \param numA float    Primer operando
 * \param numB float    Segundo operando
 * \return void
 *
 */
void obtenerResultadosOperaciones(int flagCaseTres,float numA, float numB);
