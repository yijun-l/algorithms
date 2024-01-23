#include <iostream>
#include "bdata.h"

/* check whether linked list is empty */
bool CheckEmpty(struct Node** head){
    if (*head == nullptr){
	return true;
    }

    return false;
}

/* check whether a specific Node in the linked list */
struct Node* CheckNode(struct Node** head, int dst_value){
    struct Node* traversal = *head;
    while(traversal){
	if(traversal->data == dst_value){
	    return traversal;
	}
	traversal = traversal->next;
    }
    return nullptr;
}

/* change a Node value */
void UpdateNodeValue(struct Node** head, int value, int dst_value){
    struct Node* dst = CheckNode(head, dst_value);
    if(dst){
	dst->data = value;
    }
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

/* insert Node(value) to the head of linked list */
void InsertToFirst(struct Node** head, int value){
    struct Node* new_node = new Node{value, nullptr};

    /* check whether head is NULL */
    if (CheckEmpty(head)){
        *head = new_node;	    
	return;
    }
    new_node->next = *head;
    *head = new_node;
}

/* clear the whole linked list */
void ClearLinkedList(struct Node** head){
    if (CheckEmpty(head)){
	return;
    }
    struct Node* traversal = *head;
    struct Node* tmp = nullptr;
    while(traversal){
	tmp = traversal->next;
	delete traversal;
	traversal = tmp;
    }
    *head = traversal;
}

/* remove specific node */
bool RemoveNode(struct Node** head, int dst_value){
    if (CheckEmpty(head)){
	return false;
    }

    struct Node* traversal = *head;
    if(traversal->data == dst_value){
	*head = traversal->next;
	delete traversal;
	return true;
    }
    struct Node* prev = traversal;
    traversal = traversal->next;
    while(traversal){
	if(traversal->data == dst_value){
	    prev->next = traversal->next;
	    delete traversal;
	    return true;
	}
	prev = traversal;
	traversal = traversal->next;
    }
    return false;
}

void RemoveSpecificNode(struct Node** head, int dst_value){
    if(RemoveNode(head,dst_value)){
	std::cout << "Node(" << dst_value << ") Removed, current linked list:" << std::endl;
	PrintLinkedList(head);
    }else{
	std::cout << "No such Node found!" << std::endl;
    }
}

/* swap value between the current Node and next Node */
void SwapNodeValue(struct Node** node){
    struct Node* current = *node;
    if((current == nullptr) || (current->next == nullptr)){
	return;
    }
    int tmp = current->data;
    current->data = current->next->data;
    current->next->data = tmp;
}

