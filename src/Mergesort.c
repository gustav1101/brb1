#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"
#include "Mergesort.h"




DLL* divide(DLL* originalList)
{
    DLL* list1;
    DLL* list2;
    int i;
    int q;
    
    printList(originalList);
    
    if(originalList == NULL || originalList->size == 1)
    {
	return originalList;
    }

    
    list1 = newList();
    list2 = newList();

    q = originalList->size/2;

    reset(originalList);
    
    for(i = 0; i<q; i++)
    {
	insertCopyNode(originalList->cur,list1);
	next(originalList);
	next(list1);
    }
    for(i = q; i < originalList->size; i++)
    {
	insertCopyNode(originalList->cur,list2);
	next(originalList);
	next(list2);
    }

    
    divide(list1);
    divide(list2);
    
    merge(list1, list2, originalList);
    
    clearList(list1);
    clearList(list2);
    
    return NULL;
}


void merge(DLL* list1, DLL* list2, DLL* ol)
{

    bool list1Empty;
    bool list2Empty;

    reset(list1);
    reset(list2);
    reset(ol);

    list1Empty = false;
    list2Empty = false;

    do{
	if( list1Empty )
	{
	    mergeWrite( peek(list2), ol);
	    if( !next(list2) )
	    {
		list2Empty = true;
	    }
	}
	else if( list2Empty)
	{
	    mergeWrite( peek(list1), ol);
	    if( !next(list1) )
	    {
		list1Empty = true;
	    }
	}
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

}

void mergeWrite(int val, DLL* list)
{
    list->cur->val = val;
}
