/**
 * @file Mergesort.h
 *
 * @author Lukas Kalde, Tim Bohne
 *
 * @date 24.4.2016
 *
 * @brief Mergesort that works with @c DLL
 *
 * Implementation of mergesort that works on the DLL.
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_
#include "DLL.h"

/**
 * @brief Divides the list according to mergesort algorithm
 *
 * Calls divide on two newly created lists unless @p originalList only
 * holds one element (anchor). Calls merge afterwards with both lists.
 * Sorted list will be @p originalList .
 *
 * @p originalList DLL List will be sorted after this
 */
void divide(DLL* originalList);

/**
 * @brief Merges two sublists according to mergesort algorithm
 *
 * Sorts the elements of the two sublists into @p ol (in
 * ascending order).
 *
 * @p list1 Sublist, source of Nodes
 * @p list1 Sublist, source of Nodes
 * @p ol Original List to store the sorted elements in
 */
void merge(DLL* list1, DLL* list2, DLL* ol);

/**
 * @brief Writes the @p val into the current elemen in @p list
 *
 * @param val value to write into list
 * @param List where to overwrite the current element's value
 */
void mergeWrite(int val, DLL* list);

#endif
