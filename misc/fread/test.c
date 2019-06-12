#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE* testfile = fopen("file.txt", "r"), *testfile2 = fopen("file2.txt", "w");

    char *str = malloc(sizeof(char)*25);
    fread(str, sizeof(char)*1, 1, testfile);

    for (int i = 0; i < 3; i++) {
        fwrite(str, sizeof(char), 1, testfile2);
    }


    free(str);
    fclose(testfile);
    fclose(testfile2);

}