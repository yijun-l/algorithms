#include <iostream>
#include <cstdlib>
#include <ctime>
#include "uti.h"

using namespace std;

/* 
 * Function to swap two integers using bitwise XOR 
 *
 * bitwise XOR:
 *  n ^ 0 = n
 *  n ^ n = 0
 *  a ^ b = b ^ a
 *  a ^ b ^ c = a ^ (b ^ c)
 */
void sswap(int* a, int* b){
    if(a == b){
        return;
    }
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}	

/* Function to print array values up to a specified index */
void printArr(int* arr, int index){
    cout << "Array Value: ";
    for(int i = 0; i < index; i++){
        cout <<*(arr+i)<< " ";
    }
    cout << endl;
}

/* Public printArr() function */
void pprintArr(int* arr){
    printArr(arr, ARR_LEN);
}

/* Function to generate an array with random integer members */
int* arrGen(int len, int max){
    srand(static_cast<unsigned int>(time(nullptr)));
    int* arr = new int[len];
    for(int i = 0; i < len; i++){
        *(arr+i) = rand()%max - rand()%max;
    }

    return arr;
}

/* Public arrGen() function */
int* parrGen(){
    return arrGen(ARR_LEN, ARR_MAX);
}
