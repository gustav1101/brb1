#ifndef DLLH_
#define DLLH_

struct Node {
    int val;
    Node* prev;
    Node* next;
}

    
int* parseInput(int argc, char** argv);
void printResults(int* numbers, int limit);
int debug(int lim, char* str);
void addNode(Node n);
void addNode(int val);



#endif
