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
        sswap(arr+i, arr+tmp_index);
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
		sswap(arr+j, arr+j+1);
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
		sswap(arr+j, arr+j-1);
	    }
	}
    }
    std::cout << "Insertion Sort operated." << std::endl;
}

int main(){
    int* testArr = parrGen();
    pprintArr(testArr);
    //selectionSort(testArr);
    //bubbleSort(testArr);
    insertionSort(testArr);
    pprintArr(testArr);
    return 0;
}
