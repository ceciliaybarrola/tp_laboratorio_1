#include "LinkedList.h"
#include "Employee.h"
/** \brief Controller that works as a bridge between the main and the reading of the text file
 *
 * \param path char*: file name
 * \param pArrayListEmployee LinkedList*: pointer to the linkedList where you will work
 * \return int: It returns  -2 if a file has been created, -1 if a folder could not be
 *             created,0 if there is a NULL element or the biggest ID if the file has been read
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Controller that works as a bridge between the main and the reading of the binary file
 *
 * \param path char*: file name
 * \param pArrayListEmployee LinkedList*: pointer to the linkedList where you will work
 * \return int: It returns  -2 if a file has been created, -1 if a folder could not be
 *             created,0 if there is a NULL element or the biggest ID if the file has been read
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief function that is responsible for creating an employee in dynamic memory and adding it to the linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*: Pointer to the last id created
 * \param flag int: flag that validates that a file has been read
 * \return int: Returns 0 if there is an NULL element or the file has not been read or 1 if it's OK
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id, int flag);

/** \brief Controller that works as a bridge between the main and the employee edition. It ask for an employee' id
 *         and validate that it is valid
 *
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or there isn't any employee in the linkedList, 1 if it's OK or -1 if the action has been canceled
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Controller that works as a bridge between the main and the employee elimination. It ask for an employee' id
 *         and validate that it is valid
 *
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or there isn't any employee in the linkedList, 1 if it's OK or -1 if the action has been canceled
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief function in charge of going through the linked list and listing the employees
 *
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element  or there isn't any employee or 1 if it's OK
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief function in charge of creating a copy of the list, offering a sorting menu for it and then deleting it
 *
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or there isn't any employee in the linkedList, 1 if it's OK
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief function that works as a bridge between the main and the load of the employees to the text file
 *
 * \param path char*: file name
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or there isn't any employees in the list or 1 if it's OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief function that works as a bridge between the main and the load of the employees to the binary file
 *
 * \param path char*: file name
 * \param pArrayListEmployee LinkedList*
 * \return int: Returns 0 if there is an NULL element or there isn't any employees in the list or 1 if it's OK
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




