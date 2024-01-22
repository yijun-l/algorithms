#include "bdata.h"

int main(){
    struct Node* head = nullptr;
    PrintLinkedList(&head);
    for(int i = 0 ; i < 10; i++){
	InsertToLast(&head, i);
    }
    PrintLinkedList(&head);
    return 0;
}
