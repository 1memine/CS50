#include <stdio.h>
#include <cs50.h>

int main() {
    int height = get_int("Height: ");
    for (int i = 1; i <= height; i++){

        for (int j = 1; j <= height-i; j++){
            printf(" ");
        }

        for (int k = 1; k <= i+1; k++) {
            printf("#");
        }

    printf("\n");
    }
}

