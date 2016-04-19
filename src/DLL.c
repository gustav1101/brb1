#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"

//Node* first;
//Node* last;
//Node* cur;


DLL* newList()
{
    DLL* ret = malloc(sizeof(DLL));
    return ret;
}

int add(int val, DLL* list)
{
    Node* newNode;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL )
    {
	return 1;
    }
    
    newNode->val = val;

    return addNode(newNode,list);
}


int addNode(Node* node, DLL* list)
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

    printf("Added Node with value %d\n",list->cur->val);
    return 0;

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
    if ( isEmpty(list) )
    {
	printf("List is empty");
	return;
    }
    
    Node* temp = list->first;

    printf("Values:");
    do
    {
	printf(" %d",temp->val);
	temp = temp->next;
    }while(temp != NULL);

    printf("\n");

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


    //Dobby is free!
}
