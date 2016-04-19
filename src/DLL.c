#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"

Node* first;
Node* last;
Node* cur;

int add(int val)
{
    Node* newNode;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL )
    {
	return 1;
    }
    


    newNode->val = val;

    return addNode(newNode);
}


int addNode(Node* node)
{
    //if no elements in list
    if( isEmpty() )
    {
        first = node;
	last = node;
    }
    else {
	if(hasNext())
	{
	    //set next node to point at new node
	    cur->next->prev = node;
	    //set new node's next to originally next node
	    node->next = cur->next;
	}
	else //we're at the end of the list
	{
	    //adjust 'last' pointer
	    last = node;
	}
	//in any case, set current's next to the new node
	cur->next = node;
	//and the node's previous to current
	node->prev = cur;
	
    }

    //set current to the new node
    cur = node;

    printf("Added Node with value %d\n",cur->val);
    return 0;

}

bool hasNext()
{
    if(cur->next == NULL)
    {
	return false;
    }
    return true;
}
    
bool isEmpty()
{
    return (first == NULL);
}

void printList()
{
    if (isEmpty() )
    {
	printf("List is empty");
	return;
    }
    
    Node* temp = first;

    printf("Values:");
    do
    {
	printf(" %d",temp->val);
	temp = temp->next;
    }while(temp != NULL);

    printf("\n");

}

void reset()
{
    cur = first;
}



bool next()
{
    if(cur == NULL || cur->next == NULL)
    {
	return false;
    }
    cur = cur->next;
    return true;
}

bool prev()
{
    if(cur == NULL || cur->prev == NULL)
    {
	return false;
    }
    cur = cur->prev;
    return true;
}


void clearList()
{
    cur = last;

    //if list has no elements
    if( isEmpty() )
    {
	return;
    }


    //go through list from last to first entry
    while( prev() )
    {
	//free the next element
	free(cur->next);
    }

    //now, we are at the first element. Free that as well.
    free(cur);


    //Dobby is free!
}
