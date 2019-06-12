/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"



/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int left, int right) {

    if (left <= right) {
        int mid = (left+right)/2;
        if (values[mid] == value) {
            return 1;
        } else if(value < values[mid]) {
            return search(value, values, left, mid-1);
        } else {
            return search(value, values, mid+1, right);
        }
    }
    return 0;
}



/**
 * sorts array of n values.
 */
void sort(int values[], int n)
{
    int change = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++){
            if(values[j] > values[j+1]){
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                change = 1;
            }
        }

        if(change)
            change = 0;
        else {
            return;
        }
    }
    return;
}



/**
 * Prints array of n values.
 */
void print(int values[], int n){

    printf("Array: \n");
    for(int i = 0; i < n; i++){
        printf ("%d  ", values[i]);
    }
    printf("\n");
}