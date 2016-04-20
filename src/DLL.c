#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"



DLL* newList()
{
    DLL* ret;
    ret = malloc(sizeof(DLL));
    ret->first = NULL;
    ret->last = NULL;
    ret->cur = NULL;
    ret->size = 0;
    return ret;
}

bool add(int val, DLL* list)
{
    Node* newNode;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL )
    {
	return false;
    }
    
    newNode->val = val;

    newNode->next = NULL;
    newNode->prev = NULL;
    
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

    list->size++;

    return true;

}

bool insertCopyNode(Node* node, DLL* list)
{
    return add(node->val,list);

}


int peek(DLL* list)
{
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
    Node* temp;

    if ( isEmpty(list) )
    {
	printf("List is empty");
	return;
    }
    
    temp = list->cur;

    reset(list);
    printf("Values:");
    do
    {
	printf(" %d",peek(list));
	
    }while( next(list) );

    printf("\n");

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
    list->cur = list->last;

    //if list has no elements
    if( isEmpty(list) )
    {
	return;
    }


    //go through list from last to first entry
    while( prev(list) )
    {
	//free the next element
	free(list->cur->next);
    }

    //now, we are at the first element. Free that as well.
    free(list->cur);

    free(list);

    //Dobby is free!
}
