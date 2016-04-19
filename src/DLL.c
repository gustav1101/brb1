#include "DLL.h"
#include <stdlib.h>
#include <stdbool.h>

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

    return 0;

}

int hasNext()
{
    if(cur->next == NULL)
    {
	return 0;
    }
    return 1;
}
    

void printList()
{
    Node* temp = first;

    

}
