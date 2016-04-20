#ifndef DLL_H_
#define DLL_H_
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DLL
{
    Node* first;
    Node * last;
    Node* cur;
    int size;
} DLL;


DLL* newList();
bool add(int val, DLL* list);
bool addNode(Node* node, DLL* list);
bool insertCopyNode(Node* node, DLL* list);
int peek(DLL* list);
bool hasNext(DLL* list);
bool isEmpty(DLL* list);
void printList(DLL* list);
void reset(DLL* list);
bool next(DLL* list);
bool prev(DLL* list);
void clearList(DLL* list);

#endif
