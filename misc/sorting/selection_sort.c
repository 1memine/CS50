#include <stdio.h>


int main() {

    int array[5] = {4, 3, 2, 1, 0};

    for (int i = 0; i < 5-1; i++) {
        int min = i;
        for (int j = i+1; j < 5; j++){
            if (array[min] > array[j]) {
               min = j;
            }
        }
        if (min != i) {
            int temp = 0;
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

