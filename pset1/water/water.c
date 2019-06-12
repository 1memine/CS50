#include <stdio.h>
#include <cs50.h>

int main() {
    int minutes = get_int("Minutes: ");
    printf("Bottles: %i\n", minutes*12);
}