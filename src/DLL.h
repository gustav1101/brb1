#ifndef DLL_H_
#define DLL_H_


typedef struct Node
{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;


extern int add(int val);
extern int addNode(Node* node);
int hasNext();
void printList();

#endif
