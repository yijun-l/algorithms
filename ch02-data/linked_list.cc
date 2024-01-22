#include <iostream>
#include "bdata.h"

/* check whether linked list is empty */
bool CheckEmpty(struct Node** head){
    if (*head == nullptr){
	return true;
    }

    return false;
}

/* print values in a linked list */
void PrintLinkedList(struct Node** head){
    if (CheckEmpty(head)){
	std::cout << "Empty Linked List!" << std::endl;
	return;
    }
    struct Node* traversal = *head;
    std::cout << "Linked List: ";
    while(traversal->next != nullptr){
	std::cout << traversal->data << " -> ";
	traversal = traversal->next;
    }
    std::cout << traversal->data <<  std::endl;
}

/* insert Node(value) after Node(dst_value) */
bool NodeInsert(struct Node** head, int value, int dst_value){
    struct Node* new_node = new Node{value, nullptr};
    if(CheckEmpty(head)){
	*head = new_node;
	return false;
    }

    struct Node* traversal = *head;
    while(traversal){
	if(traversal->data == dst_value){
	    new_node->next = traversal->next;
	    traversal->next = new_node;
	    return true;
	}
	traversal = traversal->next;
    }
    return false;
}

/* insert Node(value) to the tail of linked list */
void InsertToLast(struct Node** head, int value){
    struct Node* new_node = new Node{value, nullptr};

    /* check whether head is NULL */
    if (CheckEmpty(head)){
        *head = new_node;	    
	return;
    }
    struct Node* traversal = *head;
    while(traversal->next != nullptr){
	traversal = traversal->next;
    }
    traversal->next = new_node;
}

