//#include <string.h>
//#include <stdio.h>
#include "Input.h"
#define FULL 0
#define EMPTY 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief function that saves the logic of case 1
 *
 * \param counter int: is a counter that will be used to generate a unique id
 * \param employee[] sEmployee: array of employees
 * \param len int: array length
 * \return int: returns the counter or the counter decreased by one if there was
                no free space so as not to lose values ​​in the id
 *
 */
int EmployeesCaseOne(int counter,sEmployee employee[], int len);

/** \brief Funcion que guarda toda la logica del case 2
 *
 * \param counter int: receives the employee registration counter to use as a flag
  *                    and validate that at least one employee has been tinned
 * \param employee[] sEmployee: array of employees
 * \param len int: Array length
 * \return void
 *
 */
void EmployeesCaseTwo(int counter, sEmployee employee[], int len);

/** \brief Funcion que guarda toda la logica del case 3
 *
 * \param counter int: receives the employee registration counter to use as a flag
  *                    and validate that at least one employee has been tinned
 * \param employee[] sEmployee: array of employees
 * \param len int: Array length
 * \return void
 *
 */
void EmployeesCaseThree(int counter, sEmployee employee[], int len);

/** \brief Function that saves all the logic of case 4
 *
 * \param counter int: receives the employee registration counter to use as a flag
  *                    and validate that at least one employee has been tinned
 * \param employee[] sEmployee: array of employees
 * \param len int: Array length
 * \return void
 *
 */
void EmployeesCaseFour(int counter, sEmployee employee[], int len);

/** \brief Find the first free position of the array
 *
 * \param employee[] sEmployee: array of employees
 * \param len int: Array length
 * \return int: Return -1 if there isn't a free array position or free position index
 *
 */
int SearchFree(sEmployee employee[], int len);

/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 *
 * \param employee[] sEmployee: array of employees
 * \param len int: Array length
 * \return int: Return 0 if it's OK
 *
 */
int InitEmployees(sEmployee employee[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param employee[] sEmployee
 * \param len int
 * \param id int
 * \return int: Return employee index position or (-1) if [employee not found]
 *
 */
int FindEmployeeById(sEmployee employee[], int len, int id);


/** \brief requests the input of employee data and passes them as a parameter to
 *         the function addEmployee
 *
 * \param employee[] sEmployee: array of employees
 * \param len int:Array length
 * \param counter int: use the counter to generate the ID
 * \return void
 *
 */
void AddEmployeeData(sEmployee employee[], int len, int counter);

/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 *
 * \param employee[] sEmployee
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int: Return (-1) if Error [ without free space] - (0) if Ok
 *
 */
int AddEmployee(sEmployee employee[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Asks for an id, shows a menu of modifications and the user decides what
 *         to modify or if he wants to cancel the action
 *
 * \param employee[] sEmployee
 * \param len int
 * \return int: Return (-1) if Error [if can't find a employee] - (1) if Ok -
  *        (0) if the action was canceled
 *
 */
int ModifyEmployee(sEmployee employee[], int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1( Define EMPTY ))
 *
 * \param employee[] sEmployee
 * \param len int
 * \param id int
 * \return int: Return (-1) if Error [if can't find a employee] - (0) if Ok
 *
 */
int RemoveEmployee(sEmployee employee[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
 *         indicate UP or DOWN order
 *
 * \param employee[] sEmployee
 * \param len int
 * \param order int: [1] indicate UP - [0] indicate DOWN
 * \return int: (0) if Ok
 *
 */
int SortEmployees(sEmployee employee[], int len, int order);

/** \brief Sort the items in the employee array in increasing order by last name and sector
 *
 * \param employee[] sEmployee
 * \param len int
 * \return void
 *
 */
void SortGrowingEmployees (sEmployee employee[], int len);

/** \brief Sort the items in the employee array in decreasing order by last name and sector
 *
 * \param employee[] sEmployee
 * \param len int
 * \return void
 *
 */
void SortDecreasingEmployees (sEmployee employee[], int len);

/** \brief it accumulates the salary of all employees
 *
 * \param employee[] sEmployee
 * \param len int
 * \return float: return the accumulated value
 *
 */
float AccEmployeesSalary (sEmployee employee[], int len);

/** \brief this function counts the number of employees
 *
 * \param employee[] sEmployee
 * \param len int
 * \return int: return the counter value
 *
 */
int CounterEmployess(sEmployee employee[], int len);

/** \brief receives a counter and accumulator and averages
 *
 * \param acc float: salary account
 * \param counter int: employees counter
 * \return float: return average
 *
 */
float AverageEmployeesSalary(float acc, int counter);

/** \brief this function counts the employees that exceed the average salary
 *
 * \param employee[] sEmployee
 * \param len int
 * \param average float: average salary
 * \return int accountant for employees who exceed the average salary
 *
 */
int AboveAverageSalary(sEmployee employee[], int len, float average);

/** \brief print the content of employees array
 *
 * \param employee[] sEmployee
 * \param len int
 * \return int
 *
 */
int PrintEmployees(sEmployee employee[], int len);

/** \brief print the content of one employee
 *
 * \param employee[] sEmployee
 * \param index int: receives the index of the employee's position
 * \return void
 *
 */
void PrintOneEmployee(sEmployee employee[], int index);
