#include "sort.h"
#include "uti.h"

int main(){
    int* testArr = arrayGenerate();
    printArray(testArr);

    //selectionSort(testArr);
    //bubbleSort(testArr);
    //insertionSort(testArr);
    mergeSort(testArr);

    printArray(testArr);

    return 0;
}
