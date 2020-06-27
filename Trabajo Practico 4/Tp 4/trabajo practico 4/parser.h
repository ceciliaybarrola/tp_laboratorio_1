
/** \brief function responsible for parsing a text file an employee type data and adding it to the linked list
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or the max id if it's ok
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief function responsible for parsing a binary file an employee type data and adding it to the linked list
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Returns 0 if there is an NULL element or the max id if it's ok
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief funcion encargada de escribir el contenido de la linked list dentro de un archivo de texto
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int  Returns 0 if there is an NULL element or 1 if it's ok
 *
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief funcion encargada de escribir el contenido de la linked list dentro de un archivo binario
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int  Returns 0 if there is an NULL element or 1 if it's ok
 *
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);
