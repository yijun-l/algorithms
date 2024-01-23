#ifndef _DSA_DATA_STRUCTURE_H_
#define _DSA_DATA_STRUCTURE_H_

/* singly and circular linked list */
struct Node{
    int data;
    struct Node *next;
};

/* doubly linked list */
struct DoubleNode{
    int data;
    struct DoubleNode *prev;
    struct DoubleNode *next;
};

/* singly linked list functions */
void PrintLinkedList(struct Node**);
void InsertToLast(struct Node**, int);
void InsertToFirst(struct Node**, int);
bool NodeInsert(struct Node**, int, int);
void ClearLinkedList(struct Node**);
void RemoveSpecificNode(struct Node**, int);
void UpdateNodeValue(struct Node**, int, int);


#endif
