#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int encrypt(int, int);

int main(int argc, string argv[]) {
    if (argc != 2) {    //check if there's only 1 command-line arg
        printf("Usage: ./vigenere key_word\n");
        return 1;
    }

    int key_length = strlen(argv[1]), key[key_length];       //declare array of integers and var for length of key
    for (int i = 0, l = strlen(argv[1]); i < l; i++) { //check if symbols are alphabetical
        if (isalpha(argv[1][i]) ) { // if yes assign it to key array
            key[i] = (int) argv[1][i];
        } else {                    //if not stop the programm
            printf("invalid keyword\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext)];

    printf("ciphertext: ");
    for(int i = 0, j = 0, l = strlen(plaintext); i < l; i++) {

        if( isalpha(plaintext[i]) ) {   //cipher if char is alphabetical letter
            ciphertext[i] = encrypt(plaintext[i], key[j%key_length]);
            j++;
        } else {
            ciphertext[i] = plaintext[i]; //don't cipher if char isn't alphabetical letter
        }

        printf("%c", ciphertext[i]);    //print char
    }
    printf("\n");
    return 0;
}

int encrypt(int initial_value, int key_value) {

    if ( islower( (char) initial_value) ) {
        return 97 + ( initial_value-97 + key_value-97 )%26;
    } else {
        return 65 + ( initial_value-65 + key_value-65 )%26;
    }

}