#include "bdata.h"
#define LL_TEST 1

int main(){

    /* test Linked List funtions */
    if (LL_TEST){

	/* create test Linked List */
        struct Node* head = nullptr;
        PrintLinkedList(&head);
        for(int i = 0 ; i < 10; i++){
            InsertToLast(&head, i);
        }
        PrintLinkedList(&head);

	/* test basic functions */
        InsertToLast(&head, 666);
        PrintLinkedList(&head);
        InsertToFirst(&head, 888);
        PrintLinkedList(&head);
        RemoveSpecificNode(&head, 9);
        RemoveSpecificNode(&head, 8);
	UpdateNodeValue(&head, 777, 888);
        PrintLinkedList(&head);
    }

    return 0;
}
