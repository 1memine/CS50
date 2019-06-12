#include <stdio.h>
#include <cs50.h>
#include <string.h>
// Prompt user to write a string to a text file

int main(int argv, char **argc) {

    // Ensure we have only 1 arg
    if (argv != 2) {
        printf("Usage: ./typewriter XXX\n");
        return 2;
    }

    // Open file
    FILE* text = fopen(argc[1], "w");
    if (text == NULL) {
        return 2;
    }

    //Write to file
    for (char *input = get_string(); strcmp(input, "end") != 0; input = get_string()) {
        fputs(input, text);
        fputs("\n", text);
    }

    fclose(text);
    return 1;
}