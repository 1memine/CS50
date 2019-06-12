#include <stdio.h>

int main() {
    int array[5] = {4, 3, 2, 1, 0};

    int counter = 0;
    do {
       counter = 0;
       for (int i = 0; i < 5-1; i++) {
           if (array[i] > array[i+1]) {
                int temp = 0;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                counter++;
           }
       }
    } while (counter > 0);

    for (int i = 0; i < 5; i++){
        printf("%d  ", array[i]);
    }
    printf("\n");
}