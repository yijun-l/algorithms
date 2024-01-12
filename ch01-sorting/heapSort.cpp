#include <iostream>
#include "uti.h"

/* 
 * Heap Sort Algorithm
 *
 * Heap Sort is a popular and efficient sorting algorithm in computer 
 * programming.
 * Heap sort works by visualizing the elements of the array as a special 
 * kind of complete binary tree called a heap.
 * 
 * Time Complexity: O(nlogn)
 * Time Complexity Best: nlogn
 * Space Complexity: 1
 */

int shParent(int element){
    return element / 2;
}

int shLeftChild(int element){
    return element * 2 + 1;
}

int shRightChild(int element){
    return element * 2 + 2;
}

int maxElement(int* arr, int left, int right){
    return ( *(arr+left) > *(arr+right)) ? left : right;
}

void heapify(int* arr, int element){
    if (element == 0){
	return;
    }
    int parent = shParent(element);
    if ( *(arr+element) > *(arr+parent) ){
	swap(arr+element, arr+parent);
	heapify(arr, parent);
    }
}

void heapDown(int* arr, int element, int* heapSize){
    /* return when there is only one element in heap */
    if (!*heapSize){
	return;
    }

    /* if this element has right child */
    if ( shRightChild(element) <= *heapSize){
	int tmp = maxElement(arr, shLeftChild(element), shRightChild(element));
	if( *(arr+tmp) > *(arr+element)){
	    swap(arr+tmp, arr+element);
	    heapDown(arr, tmp, heapSize);
	}
    }else if( shLeftChild(element) <= *heapSize){
        int tmp = shLeftChild(element);
	if( *(arr+tmp) > *(arr+element)){
	    swap(arr+tmp, arr+element);
	}
    }

    
}

void heapRemove(int* arr, int* heapSize){
    /* return when there is only one element in heap */
    if (!*heapSize){
	return;
    }
    /* put the last element to root, then reduce heap size */
    swap(arr, arr+*heapSize);
    *heapSize = *heapSize -1;
    

    /* put root element to a proper place */
    heapDown(arr, 0, heapSize);

}

void inHeapSort(int* arr, int end){
    int heapSize = end;
    for(int i = 0; i <= end; i++){
	heapify(arr, i);
    }
    while(heapSize){
	heapRemove(arr, &heapSize);
	heapDown(arr, 0, &heapSize);
    }
}

void heapSort(int *arr){
    inHeapSort(arr, ARR_LEN - 1);
    std::cout << "Heap Sort operated." << std::endl;
}
