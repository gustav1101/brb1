#include "DLLTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mergesort.h"

// Verbose description of this class in header.

int main(int argc, char ** argv)
{
    int* numbers; //parsed input goes here
    int i;        //counter.
    DLL* list;    //List to sort
  
    if( 1 == argc )
    {
	printf("Please enter integer arguments.\n");
	return 0;
    }

    //parse input into numbers
    numbers = parseInput(argc, argv);
    //make sure malloc worked
    if (numbers == NULL)
    {
	return 1;
    }

    //allocate memory for list
    list = malloc(sizeof(DLL));
    //again test malloc
    if (list ==NULL)
    {
	return 1;
    }
    
    
    //add values into list
    for(i = 0; i<argc-1; i++)
    {
	add(numbers[i], list);
    }


    //we don't need the parsed input anymore
    free(numbers);


    printf("\nList before sorting:\n");
    printList(list);
    
    //call mergesort
    divide(list);


    //print everything
    printf("\nAfter sorting:\n");
    printList(list);


    //clear memory
    clearList(list);
  
  
    return 0;
}


int* parseInput(int argc, char**argv)
{
    int i;    //counter
    int* ret; //parsed input
    int* val; //work on this pointer instead of ret

    //allocate memory and copy first memory address of that space
    ret = (int*) malloc( (argc-1) * sizeof(int));
    val = ret;
  
    //iterate through input arguments, skip first element
    for (i = 1; i < argc; i++)
    {
	//make sure we read a valid value
	if (sscanf(argv[i], "%d", val) == EOF)
	{
	    fprintf(stderr, "Incorrect value for parsing");
	    return NULL;
	}

	//advance while still within array
	if(i+1<argc)
	{
	    val++;
	}
    }

  
    return ret;
}



void testList(DLL* list)
{
    //just test all possible operations for validity...

    printList(list);

    reset(list);

    printf("Starting Value is %d\n",peek(list) );
    if (prev(list))
    {
	printf("Hier lief was falsch");
    }
    printf("Should still be at %d\n",peek(list));
    //clearList(list);

    next(list);
    printf("At next element we have %d\n", peek(list));

    prev(list);
    printf("Here we should have again the starting element: %d\n", peek(list));

    while(next(list));

    printf("Last element should be %d\n", peek(list));

    printf("The list contains %d Elements. True? I don't know!\n",list->size);

    prev(list);
    prev(list);
    add(55,list);

    printf("Now let's add something in the middle and see if that works.\n");
    printList(list);

    printf("And what about the first element?\n");
    reset(list);
    add(42,list);
    printList(list);

}
