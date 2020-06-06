#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/** \brief show the main menu and ask for an option
 *
 * \param void
 * \return int return the option
 *
 */
int UserMenue(void);

/** \brief it generates an id by adding a counter and a constant value
 *
 * \param constant int: value that marks the number from which the id will be generated
 * \param counter int: revenue counter that allows this id to be unique
 * \return int: Return returns the sum of the constant number and the counter
 *
 */
int GetId(int maxId);

/** \brief ask for a integrer number and I validate it
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min int: minimum range
 * \param max int: maximum range
 * \return int: delivers a validated integer and within a range
 *
 */
int GetInt(char message[], char errorMessage[], int min, int max);

/** \brief validates that the array entered is an integer
 *
 * \param charArray[] char
 * \return int return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnIntNumber(char charArray[]);

/** \brief ask for a float number and I validate it
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min float: minimum range
 * \param max float: maximum range
 * \return float: delivers a validated float and within a range
 *
 */
float GetFloat(char message[], char errorMessage[], float min, float max);

/** \brief validates that the array entered is an float
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnfloatNumber(char charArray[]);

/** \brief it receives a string of characters, requests that data of this
 *         type be entered, validates that all its characters are letters
 *         and returns it by reference
 *
 * \param charArray[] char
 * \param mensaje[] char
 * \return void
 *
 */
void getString(char charArray[], char message[], char errorMessage[]);

/** \brief validates that all characters are letters
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnAlphabetString(char charArray[]);

/** \brief validate that it is a natural number
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnUnsignedIntNumber(char charArray[]);

/** \brief ask for a number and validate that it is an unsigned integer
 *
 * \param message[] char
 * \param errorMessage[] char
 * \return int delivers a validated natural number
 *
 */
int GetUnsignedInt(char message[], char errorMessage[]);

