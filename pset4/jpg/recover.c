/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 *
 * usage ./recover CARD_NAME
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {

    // Ensure proper usage
    if (argc != 2) {
        printf("usage ./recover CARD_NAME\n");
        return 1;
    }

    // Open memory card
    FILE* mem_ptr = fopen(argv[1], "r");
    if (mem_ptr == NULL) {
        fclose(mem_ptr);
        printf("There's no such file as %s", argv[1]);
        return 2;
    }


    // Declare pointer for block and pointer for file name string
    char *block_ptr = malloc(BLOCK_SIZE);
    char *title_ptr = malloc(strlen("XXX.jpg") + 1);
    FILE* img = NULL;

    // File counter
    int jpg_counter = 0;

    while(fread(block_ptr, BLOCK_SIZE, 1, mem_ptr) == 1) {

        // Check if block is the beginning of jpg
        if(block_ptr[0] == (char) 0xFF && block_ptr[1] == (char) 0xD8 && block_ptr[2] == (char) 0xFF) {
            // If there was no file opened open it else close it and open new
            if(jpg_counter == 0) {
                sprintf(title_ptr, "%03d.jpg", jpg_counter);
                img = fopen(title_ptr, "a");
            } else {
                fclose(img);
                jpg_counter++;
                sprintf(title_ptr, "%03d.jpg", jpg_counter);
                img = fopen(title_ptr, "a");
            }

            // Write block to opened file
            fwrite(block_ptr, BLOCK_SIZE, 1, img);
        } else if(jpg_counter != 0) {
            // Write block to opened file if it exists
            fwrite(block_ptr, BLOCK_SIZE, 1, img);
        }
    }
    // Close all files and free all pointers
    fclose(img);
    fclose(mem_ptr);
    free(block_ptr);
    free(title_ptr);
}
