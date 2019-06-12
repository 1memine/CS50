#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main() {
    string name = get_string("Name: ");

    for (int i = 0, k = 0,  j = strlen(name); i < j; i++){ //from second symbol to last

        if(name[i] == ' ') {
            k = 0;
        }

        if (k == 0  && isalpha(name[i])) {
            printf("%c", toupper(name[i]) );
            k = 1;
        }
    }
    printf("\n");
}



