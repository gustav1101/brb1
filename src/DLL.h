/**
 * @file DLL.h
 *
 * @author Lukas Kalde
 *
 * @date 24.4.2016
 *
 * @brief Double linked list to work with
 *
 * Includes the DLL struct as header for the list,
 * the Node struct that stores the value and a lot of
 * functions that work on the list.
 *
 */

#ifndef DLL_H_
#define DLL_H_
#include <stdbool.h>

/**
 * @brief Node holding current value and connects to other elements
 *
 * Holds @c int value and pointer to next as well as to previous
 * element.
 *
 */
typedef struct Node
{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;


/**
 * @brief Double Linked List header
 *
 * Use this for most operations on the list, only access @c Node
 * if neccessary. Many functions have been implemented to work
 * on the list to improve readability and maintenance of code.
 *
 */
typedef struct DLL
{
    Node* first;  //Points to first element
    Node * last;  //Points to last element
    Node* cur;    //Current element
    int size;     //Size of list (Number of all nodes)
} DLL;

/**
 * @brief Get a new list
 *
 * Creates a new list and returns the struct.
 * 
 * @return a new, empty list
 */
DLL* newList();


/**
 * @brief Add a new integer behind current element
 * 
 * Automatically creates new Node and puts it in place
 * behind current element by calling @c addNode .
 *
 * @param val value of the node
 * @param list List to which the value will be added
 * @return true if successful, false if not
 */
bool add(int val, DLL* list);


/**
 * @brief Adds existing Node to the list
 *
 * Does not create a copy but inserts the Node as is! For
 * creating a (deep) copy use @c insertCopyNode .
 * Appends @p node behind current element.
 *
 * @param node Node to be added
 * @param list List to which the Node will be added
 * @return true if successful, false if not
 */
bool addNode(Node* node, DLL* list);

/**
 * @brief Inserts (deep) copy of Node into @p list
 *
 * Copy will be appended after current element. All
 * values will be deep copys of the original node, so
 * changing one has no effect on the other.
 *
 * @param node Node to be copied
 * @param list List to cope the Node into
 * @return true if successful, false if not
 */
bool insertCopyNode(Node* node, DLL* list);

/**
 * @brief Get value of current element
 *
 * Returns the value of the current value without
 * changing anything in the list.
 *
 * @param list List in that the value is
 * @return value of current node in @p list
 */
int peek(DLL* list);

/**
 * @brief Does the current element has a successor?
 *
 * @param list List with the relevant Node
 * @return true if element after current exists, false if null
 */
bool hasNext(DLL* list);

/**
 * @brief is the @p list empty?
 *
 * @param list List to be checked
 * @return true if list is empty, false else
 */
bool isEmpty(DLL* list);

/**
 * @brief Prints the @p list
 *
 * Prints all elements in the list from beginning to
 * end on console. Current element is not changed by this.
 *
 * @param list List to print
 */
void printList(DLL* list);

/**
 * @brief set Current to first element
 *
 * @param list List to reset
 */
void reset(DLL* list);

/**
 * @brief Iterate forward through list
 *
 * Current will point to next element after this.
 * If there is no element after current then current
 * will remain unchanged.
 *
 * @param list List to iterate through
 * @return true if advancing was successful, false if no next element
 */
bool next(DLL* list);

/**
 * @brief Iterate backward through list
 *
 * Current will point to previous element after this.
 * If there is no element before current then current
 * will remain unchanged.
 *
 * @param list List to iterate through
 * @return true if reversing was successful, false if no prev element
 */
bool prev(DLL* list);

/**
 * @brief free all memory
 * 
 * Clearing includes @p list .
 *
 * @param list List to clear
 */
void clearList(DLL* list);

#endif
