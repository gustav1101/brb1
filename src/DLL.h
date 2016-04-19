#ifndef DLL_H_
#define DLL_H_
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;


int add(int val);
int addNode(Node* node);
bool hasNext();
bool isEmpty();
void printList();
void reset();
bool next();
bool prev();
void clearList();

#endif
