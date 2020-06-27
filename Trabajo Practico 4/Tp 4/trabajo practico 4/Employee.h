#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Controller.h"

typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    float salary;

}Employee;

/** \brief function in charge of creating an employee in dynamic memory and returning it
 *
 * \return Employee*: Pointer to employee
 *
 */
Employee* employee_new();

/** \brief function in charge of entering the parsed data in a pointer to an employee generated
 *         in dynamic memory and returning it
 *
 * \param idStr char*: Id recived as a string which will be parsed to int
 * \param nameStr char*: Name recived as a pointer to char
 * \param hoursWorkedStr char*: Hours worked recived as a string which will be parsed to int
 * \param salaryStr char*: Salary recived as a string which will be parsed to float
 * \return Employee*: Pointer to employee
 *
 */
Employee* employee_newParameters(char* idStr,char* nameStr,char* hoursWorkedStr,char* salaryStr);

/** \brief function responsible for removing an employee from the linkedList, receiving
 *         this and the index. This function calls to the function ll_remove
 *
 * \param pArrayListEmployee LinkedList*: Linked list
 * \param index int: position of the pointer to the employee in the linkedList
 * \return int: Return 1 if the employee has been deleted, -1 if the action has been canceled or 0 if the linkedList is NULL
 *
 */
int employee_delete(LinkedList* pArrayListEmployee, int index);

/** \brief function responsible for modifying an employee from the linkedList, receiving
 *         this and the index.
 *
 * \param pArrayListEmployee LinkedList*: Linked list loaded with pointers to users
 * \param index int: position of the pointer to the employee in the linkedList
 * \return int: Return 1 if the employee has been modified, -1 if the action has been canceled or 0 if the linkedList is NULL
 *
 */
int employee_edit(LinkedList* pArrayListEmployee, int index);

/** \brief function in charge of going through the linked list, obtaining each employee
 *         and comparing the employees' id with the id entered by the user until the same id is found
 *
 * \param pArrayListEmployee LinkedList*: Linked list loaded with pointers to users
 * \param id int
 * \return int: Return th index if the employee has been found or -1 if the empoyee' id has not been found
 *
 */
int employee_FindById(LinkedList* pArrayListEmployee, int id);

/** \brief  function in charge of reciving a pointer to employee and print the data
 *
 * \param employee Employee*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_PrintOneEmployee(Employee* employee);

/** \brief id setter
 *
 * \param employee Employee*
 * \param id int
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_setId(Employee* employee,int id);

/** \brief  getter id
 *
 * \param employee Employee*
 * \param id int*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_getId(Employee* employee,int* id);

/** \brief  name setter
 *
 * \param employee Employee*
 * \param name char*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_setName(Employee* employee,char* name);

/** \brief  getter name
 *
 * \param employee Employee*
 * \param name char*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_getName(Employee* employee,char* name);

/** \brief  Hours worked setter
 *
 * \param employee Employee*
 * \param hoursWorked int
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_setHoursWorked(Employee* employee,int hoursWorked);

/** \brief  getter hours worked
 *
 * \param employee Employee*
 * \param hoursWorked int*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_getHoursWorked(Employee* employee,int* hoursWorked);

/** \brief  Salary setter
 *
 * \param employee Employee*
 * \param salary float
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_setSalary(Employee* employee,float salary);

/** \brief  getter Salary
 *
 * \param employee Employee*
 * \param salary float*
 * \return int: Returns 0 if there is an NULL element or 1 if it's OK
 *
 */
int employee_getSalary(Employee* employee,float* salary);

/** \brief  It's compares the names of two employees
 *
 * \param employee1 void*: pointer to void to be cast to pointer to employee
 * \param employee2 void*: pointer to void to be cast to pointer to employee
 * \return int: Returns 0 if there is an NULL element or the strcimp between both names
 *
 */
int employee_CompareByName(void* employee1, void* employee2);

/** \brief
 *
 * \param employee1 void*:pointer to void to be cast to pointer to employee
 * \param employee2 void*:pointer to void to be cast to pointer to employee
 * \return int: Returns 1 if the first employee' id is greater than the second employee' id
 *
 */
int employee_CompareById(void* employee1, void* employee2);

/** \brief
 *
 * \param employee1 void*:pointer to void to be cast to pointer to employee
 * \param employee2 void*:pointer to void to be cast to pointer to employee
 * \return int Returns 1 if the first employee' salary is greater than the second employee' salary
 *
 */
int employee_CompareBySalary(void* employee1, void* employee2);

/** \brief
 *
 * \param employee1 void*:pointer to void to be cast to pointer to employee
 * \param employee2 void*:pointer to void to be cast to pointer to employee
 * \return int Returns 1 if the first employee' Hours Worked is greater than the second employee' Hours Worked
 *
 */
int employee_CompareByHoursWorked(void* employee1, void* employee2);

#endif //employee_H_INCLUDED

