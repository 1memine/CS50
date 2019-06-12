#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argv, char **argc){

    // Ensure we have only 1 arg
    if (argv != 2) {
        printf("Usage: ./typewriter XXX\n");
        return 2;
    }

    // Open file
    FILE* text = fopen(argc[1], "r");
    if (text == NULL) {
        return 2;
    }

    // Read from file
    for(char *buffer = malloc(256*sizeof(char)); fgets(buffer, sizeof(buffer), text) != NULL; ){
        printf("%s", buffer);
        printf("pointer to file: %p\n", text);
    }


    fclose(text);
    return 1;
}