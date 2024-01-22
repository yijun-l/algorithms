#ifndef _DSA_DATA_STRUCTURE_H_
#define _DSA_DATA_STRUCTURE_H_

struct Node{
    int data;
    struct Node *next;
};

void PrintLinkedList(struct Node**);
void InsertToLast(struct Node**, int);
bool NodeInsert(struct Node**, int, int);


#endif
