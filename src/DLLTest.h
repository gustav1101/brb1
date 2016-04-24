/**
 * @file DLLTest.h
 *
 * @author Lukas Kalde, Tim Bohne
 *
 * @date 24.4.2016
 *
 * @brief Calls the mergesort algorithm
 *
 * Call with input on console, separate integer values with space.
 * Calls mergesort in Mergesort.h. Prints final results.
 */

#ifndef DLLH_TEST_
#define DLLH_TEST_

#include "DLL.h"
    
/**
 * @brief parse input string into int array
 *
 * @param argc number of input arguments
 * @param argv original input from console
 *
 * @return int array with all elements parsed
 */
int* parseInput(int argc, char** argv);

/**
 * @brief call this to test the List implementation
 *
 * Tests most operations on the list and some special cases
 *
 * @param list List with example elements
 */
void testList(DLL* list);

#endif
