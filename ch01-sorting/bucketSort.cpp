#include <iostream>
#include "uti.h"

/* 
 * Bucket Sort Algorithm
 *
 * Bucket Sort is a sorting algorithm that divides the unsorted array 
 * elements into several groups called buckets. Each bucket is then sorted 
 * by using any of the suitable sorting algorithms or recursively applying 
 * the same bucket algorithm.
 *
 * Finally, the sorted buckets are combined to form a final sorted array.
 * 
 * Time Complexity: O(n^2)
 * Time Complexity Best: n+k
 * Space Complexity: n+k
 */

/* node is the type of element in a bucket */
typedef struct Node{
    int data;
    struct Node* next;
} node;


/* elements are first scattered into buckets then the elements in each 
 * bucket are sorted. Finally, the elements are gathered in order.*/
int scatterGather(int* arr, int end, node** bucket, int divisor){
    int again = 0;	
    /* Scatter: put array element to proper bucket*/
    for(int i = 0; i <= end; i++){
	int bucket_index = ((*(arr+i)) / divisor) % 10;
	if (again || (*(arr+i) / divisor)){
	    again = 1;
	}
	if (*(bucket+bucket_index) == nullptr){
	    *(bucket+bucket_index) = new node{*(arr+i), nullptr};
	} else {
	    node* tmp = *(bucket+bucket_index);
	    while(tmp->next){
	        tmp = tmp->next;
	    }
	    tmp->next = new node{*(arr+i), nullptr};
	}
    }
    if(!again){
	return 0;
    }
    /* Gather: put element back to array */
    int index = 0;
    for (int j = 0; j < 10; j++){
	node* tmp= *(bucket+j);
	while(tmp){
	    *(arr+index) = tmp->data;
	    index++;
	    node* swp = tmp;
	    tmp = tmp->next;
	    delete swp;
	}
	*(bucket+j) = nullptr;
    }

    return divisor * 10;
}

void inBucketSort(int* arr, int end){
    /* create 10 bucket to store 0-9 */
    node* bucket[10] = {nullptr};

    int divisor = 1;
    while(divisor){
	divisor = scatterGather(arr, end, bucket, divisor);
    }
    
}

void bucketSort(int *arr){
    inBucketSort(arr, ARR_LEN - 1);
    std::cout << "Bucket Sort operated." << std::endl;
}
