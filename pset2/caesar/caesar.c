#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    if (argc != 2) {    //check if there's only 1 command-line arg
        printf("Usage: ./caesar key_value\n");
        return 1;
    }
    int key = atoi(argv[1])%26; // shift key to int
    string plaintext =  get_string("plaintext:  ");  //get plain text
    char ciphertext[strlen(plaintext)]; // define array for ciphertext

    printf("ciphertext: ");
    for(int i = 0, l = strlen(plaintext); i < l; i++) {

        if( isalpha(plaintext[i]) ) {   //cipher if char is alphabetical letter
            if (islower(plaintext[i])) {
                ciphertext[i]= 97 + (plaintext[i]-97+key)%26;   //plaintext+key can't be more than 97+26, lower case
            } else {
                ciphertext[i]= 65 + (plaintext[i]-65+key)%26;   //plaintext+key can't be more than 97+26, upper case
            }
        } else {
            ciphertext[i] = plaintext[i]; //don't cipher if char isn't alphabetical letter
        }

        printf("%c", ciphertext[i]);    //print char
    }
    printf("\n");
    return 0;
}