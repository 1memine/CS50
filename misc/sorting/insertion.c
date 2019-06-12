#include <stdio.h>


int main() {

    int array[5] = {4, 3, 2, 1, 0};

    for (int i = 0; i < 5; i++){
        int temp = array[i], j = i;
        while ( j > 0 && array[j-1] > temp ) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
    }

    for (int i = 0; i < 5; i++){
        printf("%d  ", array[i]);
    }
    printf("\n");
}

