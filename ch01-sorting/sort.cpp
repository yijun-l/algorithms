#include <iostream>
#include "uti.h"

/* 
 * Selection Sort Algorithm
 *
 * Selection sort is a sorting algorithm that selects the smallest 
 * element from an unsorted list in each iteration and places that 
 * element at the beginning of the unsorted list.
 * 
 * Time Complexity: O(n^2)
 * Time Complexity Best: n^2
 * Space Complexity: 1
 */

void selectionSort(int* arr){
    int index = ARR_LEN;
    if (index < 2){
        return;
    }
    for (int i = 0; i < index-1; i++){
        int tmp_index;
        tmp_index = i;
        for (int j = i; j < index; j++){
            if(*(arr+j) < *(arr+tmp_index)){
                tmp_index = j;
            }
        }
        swap(arr+i, arr+tmp_index);
    }
    std::cout << "Selection Sort operated." << std::endl;
}

/* 
 * Bubble Sort Algorithm
 *
 * Bubble sort is a sorting algorithm that compares two adjacent elements 
 * and swaps them until they are in the intended order.
 *
 * Just like the movement of air bubbles in the water that rise up to the 
 * surface, each element of the array move to the end in each iteration. 
 * Therefore, it is called a bubble sort.
 * 
 * Time Complexity: O(n^2)
 * Time Complexity Best: n
 * Space Complexity: 1
 */

void bubbleSort(int* arr){
    int index = ARR_LEN;
    bool swapped = false;
    if (index < 2){
        return;
    }
    for (int i = 0; i < index - 1; i++){
	for (int j = 0; j < index - i; j++){
	    if(*(arr+j) > *(arr+j+1)){
		swap(arr+j, arr+j+1);
		swapped = true;
	    }
	}
	if(!swapped){
	    break;
	}
    }
    std::cout << "Bubble Sort operated." << std::endl;

}

/* 
 * Insertion Sort Algorithm
 *
 * Insertion sort is a sorting algorithm that places an unsorted element 
 * at its suitable place in each iteration.
 *
 * Insertion sort works similarly as we sort cards in our hand in a card 
 * game.
 *
 * We assume that the first card is already sorted then, we select an 
 * unsorted card. If the unsorted card is greater than the card in hand, 
 * it is placed on the right otherwise, to the left. In the same way, 
 * other unsorted cards are taken and put in their right place.
 * 
 * Time Complexity: O(n^2)
 * Time Complexity Best: n
 * Space Complexity: 1
 */

void insertionSort(int* arr){
    int index = ARR_LEN;
    if (index < 2){
        return;
    }
    for (int i = 0 ; i < index - 1 ; i++){
	for ( int j = i + 1; j > 0 ; j--){
	    if (*(arr+j) >= *(arr+j-1)){
		break;
	    }else{
		swap(arr+j, arr+j-1);
	    }
	}
    }
    std::cout << "Insertion Sort operated." << std::endl;
}

/* 
 * Merge Sort Algorithm
 *
 * Merge Sort is one of the most popular sorting algorithms that is based 
 * on the principle of Divide and Conquer Algorithm.
 *
 * Here, a problem is divided into multiple sub-problems. Each sub-problem 
 * is solved individually. Finally, sub-problems are combined to form the 
 * final solution.
 * 
 * Time Complexity: O(nlogn)
 * Time Complexity Best: nlogn
 * Space Complexity: n
 */

void merge(int* arr, int begin, int middle, int end){
    int *tmp = new int[end+1];
    int i = begin;
    int j = middle+1;
    int c = 0;

    while((i <= middle) && (j <=end)){
	//*(tmp+c++) = (*(arr+i) < *(arr+j)) ? *(arr+i++) : *(arr+j++);
	if(*(arr+i) <= *(arr+j)){
	    *(tmp+c) = *(arr+i);
	    i++;
	}else{
	    *(tmp+c) = *(arr+j);
	    j++;
	}
	c++;
    }

    while(i <= middle){
	//*(tmp+c++) = *(arr+i++);
	*(tmp + c) = *(arr + i);
	i++;
	c++;
    }

    while(j <= end){
	//*(tmp+c++) = *(arr+j++);
	*(tmp + c) = *(arr + j);
        j++;
        c++;
    }
    
    c = 0;
    while(begin+c <= end){
	*(arr + begin + c) = *(tmp + c);
	c++;
    }
    delete[] tmp;
}


void inMergeSort(int* arr, int begin, int end){
    if(begin >= end){
        return;
    }
    int middle = begin + ((end - begin) >> 1);
    inMergeSort(arr, begin, middle);
    inMergeSort(arr, middle + 1, end);
    merge(arr, begin, middle, end);
    
}

void mergeSort(int* arr){
    inMergeSort(arr, 0, ARR_LEN - 1);
    std::cout << "Merge Sort operated." << std::endl;
} 

/* 
 * Quick Sort Algorithm
 *
 * Quicksort is a sorting algorithm based on the divide and conquer 
 * approach where:
 *
 * 1. An array is divided into subarrays by selecting a pivot element 
 * (element selected from the array).
 * While dividing the array, the pivot element should be positioned 
 * in such a way that elements less than pivot are kept on the left 
 * side and elements greater than pivot are on the right side of the 
 * pivot.
 *
 * 2. The left and right subarrays are also divided using the same 
 * approach. This process continues until each subarray contains a 
 * single element.
 *
 * 3. At this point, elements are already sorted. Finally, elements are 
 * combined to form a sorted array.
 * 
 * Time Complexity: O(n^2)
 * Time Complexity Best: nlogn
 * Space Complexity: logn
 */

void divide(int* arr, int begin, int end, int pivot, int* rc){
    int i = begin;	/* index */
    int m = begin - 1;	/* point to the last element of <  pivot */
    int n = end;	/* point to the first element of > pivot */

    /* put pivot to the end */
    swap(arr+pivot, arr+end);
    n--;

    while(i <= n){
	if ( *(arr+i) > *(arr+end) ){
	    swap(arr+i, arr+n);
	    n--;
	} else if ( *(arr+i) == *(arr+end) ){
	    i++;
	}else{
	    m++;
	    swap(arr+m, arr+i);
	    i++;
	}
    }

    n++;	/* move n to the last first element of > pivot */
    swap(arr+n, arr+end);
    n++;

    *(rc+0) = m;
    *(rc+1) = n;

}

void inQuickSort(int* arr, int begin, int end){
    if (begin >= end){
	return;
    }
    int pivot = randomDigitGenerate(begin, end);
    int* rc = new int[2];
    divide(arr, begin, end, pivot, rc);
    inQuickSort(arr, begin, rc[0]);
    inQuickSort(arr, rc[1], end);
    delete[] rc;
}

void quickSort(int* arr){
    inQuickSort(arr, 0, ARR_LEN - 1);
    std::cout << "Quick Sort operated." << std::endl;
} 

