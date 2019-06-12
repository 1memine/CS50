#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void capitalize (char);

int main() {
    string name = get_string("Name: ");

    capitalize(name[0]);
    for (int i = 0, j = strlen(name); i < j; i++){
        if(name[i] == ' ') {
            capitalize(name[i+1]);
        }
    }
    printf("\n");

}

void capitalize (char letter) {
    if ( letter > 96 && letter < 123 ) {
        printf("%c", letter-32);
    } else {
        printf("%c", letter);
    }
}
