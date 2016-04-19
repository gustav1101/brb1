#ifndef DLL_H_
#define DLL_H_
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;


extern int add(int val);
extern int addNode(Node* node);
bool hasNext();
bool isEmpty();
void printList();

#endif
