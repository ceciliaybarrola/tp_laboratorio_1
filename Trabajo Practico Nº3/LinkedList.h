/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif
//Publicas

/** \brief Creates a new LinkedList in memory dynamically
 *
 *  \param void
 *  \return LinkedList* Returns (NULL) in case of not getting memory space
 *          or the pointer to the reserved space
 */
LinkedList* ll_newLinkedList(void);

/** \brief Returns the number of items in the list
 *
 * \param this LinkedList* Pointer to list
 * \return int Returns (-1) if the pointer is NULL or the number of elements in the list
 *
 */
int ll_len(LinkedList* this);

/** \brief  Add an item to the list
 * \param pList LinkedList* Pointer to list
 * \param pElement void* Pointer to the item to be added
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (0) If it worked correctly
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief It allows to test the addNode function which is private
 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Location of the item to obtain
 * \return void* Returns (NULL) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                         (pElement) If I work correctly
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief Remove an item from the list
 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Location of the item to be removed
 * \return int Returns (-1) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                       ( 0) If it worked correctly
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief Remove all items from list and list
 *
 * \param this LinkedList* Pointer to list
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (0) If it worked correctly
 *
 */
int ll_deleteLinkedList(LinkedList* this);

/** \brief Sort the list items using the received criterion function as parameter
 * \param pList LinkedList* Pointer to list
 * \param pFunc (*pFunc) Pointer to the criterion function
 * \param order int  [1] Indicates ascending order - [0] Indicates descending order
 * \return int Returns (-1) Error: if the pointer to the lists is NULL
                                (0) if it's ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/** \brief it creates and return a new list with the elements of the list passed as parameter
 *
 * \param pList LinkedList* Pointer to list
 * \return LinkedList* Returns (NULL) Error: if the pointer to the lists is NULL
                                (pointer to the new list) Yes ok
*/
LinkedList* ll_clone(LinkedList* this);

/** \brief Remove all items from the list
 *
 * \param this LinkedList* Pointer to list
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (0) If it worked correctly
 *
 */
int ll_clear(LinkedList* this);

/** \brief Find the index of the first occurrence of the element passed as parameter
 *
 * \param this LinkedList* Pointer to list
 * \param pElement void* Pointer to element
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (item index) If it worked correctly
 *
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** \brief Indicates whether the list is empty or not
 *
 * \param this LinkedList* Pointer to list
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (0) If the list is NOT empty
                        (1) If the list is empty
 *
 */
int ll_isEmpty(LinkedList* this);

/** \brief Modify an item in the list
 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Location of the element to be modified
 * \param pElement void* Pointer to the new item
 * \return int Returns (-1) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                        (0) If it worked correctly
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief Insert a new item in the list at the indicated position

 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Location where the new item will be added
 * \param pElement void* Pointer to the new item
 * \return int Returns (-1) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                        (0) If it worked correctly
 *
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** \brief Deletes the element from the indicated position and returns its pointer
 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Item location remove
 * \return void* Returns (NULL) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                            (pElement) If I work correctly
 *
 */
void* ll_pop(LinkedList* this,int index);

/** \brief  Determines whether or not the list contains the element passed as a parameter
 *
 * \param this LinkedList* Pointer to list
 * \param pElement void* Pointer of the element to verify
 * \return int Returns (-1) Error: if the pointer to the list is NULL
                        (1) If it contains the item
                        (0) if it does not contain the element
*/
int ll_contains(LinkedList* this, void* pElement);

/** \brief  Determines if all the items in the list (this2)
            are contained in the list (this)
 *
 * \param this LinkedList* Pointer to list
 * \param this2 LinkedList* Pointer to list
 * \return int Returns (-1) Error: if any of the pointers to the lists are NULL
                        (1) If the elements of (this2) are contained in the list (this)
                        (0) if the elements of (this2) are NOT contained in the list (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** \brief Create and return a new list with the indicated elements
 *
 * \param pList LinkedList* Pointer to list
 * \param from int Index from which the elements are copied in the new list
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Returns (NULL) Error: if the pointer to the lists is NULL
                                or (if the from index is less than 0 or greater than the len of the list)
                                or (if the to index is less than or equal to from or greater than the len of the list)
                         (pointer to the new list) if it's ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief  It allows to test the getNode function which is private
 *
 * \param this LinkedList* Pointer to list
 * \param index int Index of the node to obtain
 * \return Node* Returns (NULL) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                        (pElement) If I work correctly
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/** \brief It allows to test the addNode function which is private
 *
 * \param this LinkedList* Pointer to list
 * \param nodeIndex int Location where the new node will be added
 * \param pElement void* Pointer to the element to be contained by the new node
 * \return int Returns (-1) Error: if the pointer to the list is NULL or (if the index is less than 0 or greater than the len of the list)
                        (0) If it worked correctly
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

