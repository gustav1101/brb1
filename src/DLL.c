#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"

Node* first;
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
    if(first == NULL)
    {
        first = node;
	cur = node;
    }
    else {
	cur->next = node;
	node->prev = cur;
	cur = node;
    }
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
