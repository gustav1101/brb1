#include <stdlib.h>
#include <stdio.h>

#include "Mergesort.h"




void divide(DLL* originalList)
{
    //split the Nodes as even as possible between
    DLL* list1; //sublist 1
    DLL* list2; //and sublist 2
    int i; //just a counter
    int q; //half the size of list
        
    //make sure we have something to do, also anchor
    if(originalList == NULL || originalList->size == 1)
    {
	return;
    }


    //prepare the sublists
    list1 = newList();
    list2 = newList();

    //store half size
    q = originalList->size/2;

    //prepare to iterate through list
    reset(originalList);
    
    //for the first q elements, sort everything into first list
    for(i = 0; i<q; i++)
    {
	insertCopyNode(originalList->cur,list1);
	next(originalList);
	next(list1);
    }
    //second half into other sublist
    for(i = q; i < originalList->size; i++)
    {
	insertCopyNode(originalList->cur,list2);
	next(originalList);
	next(list2);
    }
    //Print current state of things
    printf("Split the following list:");
    printList(originalList);

    //recursion: call until all lists only have one element
    divide(list1);
    divide(list2);


    printf("Created sublists:\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    
    
    //merge the lists afterwards. list1 and list2 are now sorted already.
    merge(list1, list2, originalList);
    
    //clear the sublists, they are not needed anymore
    clearList(list1);
    clearList(list2);
    
}


void merge(DLL* list1, DLL* list2, DLL* ol)
{
    bool list1Empty; //true when list1 has all elements already read
    bool list2Empty; //same for sublist 2

    //Print list...
    printf("Merge called on ");
    printList(ol);
    
    //prepare to iterate through all elements
    reset(list1);
    reset(list2);
    reset(ol);

    list1Empty = false;
    list2Empty = false;

    //iterate through original list
    do{
	//if all elements from list1 were already copied:
	if( list1Empty )
	{
	    //write next value from second list
	    mergeWrite( peek(list2), ol);

	    //check if list2 has still elements after this
	    //(this should not really be necessary)
	    if( !next(list2) )
	    {
		list2Empty = true;
	    }
	}
	//same for sublist 2
	else if( list2Empty)
	{
	    mergeWrite( peek(list1), ol);
	    if( !next(list1) )
	    {
		list1Empty = true;
	    }
	}
	//here we need to actually compare values of the two lists
	//write smaller value into next list position
	else if ( peek(list1) < peek(list2) )
	{
	    mergeWrite( peek(list1), ol);
	    if( !next(list1) )
	    {
		list1Empty = true;
	    }
	}
	else
	{
	    mergeWrite( peek(list2), ol);
	    if( !next(list2) )
	    {
		list2Empty = true;
		//also we probably have a problem here...
	    }
	}
    }while(next(ol));

    //Print result...
    printf("Subset sorted: ");
    printList(ol);
}

void mergeWrite(int val, DLL* list)
{
    list->cur->val = val;
    //I was just lazy.
}
