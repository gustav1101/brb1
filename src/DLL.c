#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"


DLL* newList()
{
    DLL* ret;  //return this later
    ret = malloc(sizeof(DLL));
    ret->first = NULL;
    ret->last = NULL;
    ret->cur = NULL;
    ret->size = 0;
    return ret;
}

bool add(int val, DLL* list)
{
    //Create new node

    Node* newNode;

    newNode = malloc(sizeof(Node));

    //check if malloc was successful
    if (newNode == NULL )
    {
	return false;
    }

    newNode->val = val;

    newNode->next = NULL;
    newNode->prev = NULL;
    
    //call addNode to actually add the node into the list
    return addNode(newNode,list);
}



bool addNode(Node* node, DLL* list)
{
    //if no elements in list
    if( isEmpty(list) )
    {
        list->first = node;
	list->last = node;
    }
    else {
	if(hasNext(list))
	{
	    //set next node to point at new node
	    list->cur->next->prev = node;
	    //set new node's next to originally next node
	    node->next = list->cur->next;
	}
	else //we're at the end of the list
	{
	    //adjust 'last' pointer
	    list->last = node;
	}
	//in any case, set current's next to the new node
	list->cur->next = node;
	//and the node's previous to current
	node->prev = list->cur;
	
    }

    //set current to the new node
    list->cur = node;

    //and increase list size
    list->size++;

    return true;  //all good if we reached this point.

}

bool insertCopyNode(Node* node, DLL* list)
{
    //just call add with the value of the original node
    return add(node->val,list);
}


int peek(DLL* list)
{
    //This might not be very efficient to handle not initialised current,
    //but this should never happen in first place...
    if (list->cur == NULL)
    {
	return -1;
    }
    return list->cur->val;
}


bool hasNext(DLL* list)
{
    if(list->cur->next == NULL)
    {
	return false;
    }
    return true;
}
    
bool isEmpty(DLL* list)
{
    return (list->first == NULL);
}

void printList(DLL* list)
{
    Node* temp;  //will be used to rebuild current value

    if ( isEmpty(list) )
    {
	printf("List is empty");
	return;
    }

    //save current
    temp = list->cur;

    //first reset list, then iterate through and print each value
    reset(list);
    printf("Values:");

    do
    {
	printf(" %d",peek(list));	
    }while( next(list) );

    printf("\n"); //new line...

    //restore current
    list->cur = temp;
}

void reset(DLL* list)
{
    list->cur = list->first;
}



bool next(DLL* list)
{
    if(list->cur == NULL || list->cur->next == NULL)
    {
	return false;
    }
    list->cur = list->cur->next;
    return true;
}

bool prev(DLL* list)
{
    if(list->cur == NULL || list->cur->prev == NULL)
    {
	return false;
    }
    list->cur = list->cur->prev;
    return true;
}




void clearList(DLL* list)
{
    list->cur = list->last; //iterate from rear to front.

    //if list has no elements
    if( isEmpty(list) )
    {
	return;
    }


    //go through list from last to first entry
    while( prev(list) )
    {
	//free the prev element
	free(list->cur->next);
    }

    //now, we are at the first element. Free that as well.
    free(list->cur);

    //finally free the list element itself
    free(list);

    //Dobby is free!
}
