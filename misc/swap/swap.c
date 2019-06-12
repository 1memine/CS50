#include <stdio.h>

void swap(int *, int *);

int main(){
    int a = 1, b = 2;
    printf("Not swapped = %d and %d\n", a, b);
    swap(&a, &b);
    printf("Swapped = %d and %d\n", a, b);
}

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;

}


/*
void swap(int *x, int *y) {
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}
*/