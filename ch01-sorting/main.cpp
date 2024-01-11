#include "sort.h"
#include "uti.h"
#include <iostream>

int main(){
    int* testArr = arrayGenerate();
    printArray(testArr);

    //selectionSort(testArr);
    //bubbleSort(testArr);
    //insertionSort(testArr);
    //mergeSort(testArr);
    quickSort(testArr);
    printArray(testArr);


    return 0;
}
