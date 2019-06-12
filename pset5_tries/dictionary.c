/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

node *root;
unsigned int words = 0;


/**
 * Gets integer value of alphabetical symbol
 */
int get_index(char symbol){
    if(isalpha(symbol)) {
        return (int) tolower(symbol) - 'a';
    } else if (symbol == '\'' ) {
        return 26;
    }
    return false;
}

/**
 * Set all children of dictionary struct to NULL
 * use to avoid valgrind errors
 */
void set_alphabet_to_null (node* x){
    for (int i = 0; i < 27; i++) {
        x->alphabet[i] = NULL;
        x->is_word = false;
    }
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary) {
    // Open dictionary file and check if it exists
    FILE* dictionary_file = fopen(dictionary, "r");
    if(!dictionary_file) {
        printf("Couldn't open dictionary file.\n");
        return false;
    }


    // Allocate memory for root of the dictionary
    if(!root) {
        root = malloc(sizeof(node));
        set_alphabet_to_null(root);
    }


    // Preparation for getting chars from file one by one
    int index; node *crawler;
    for (int c = fgetc(dictionary_file), i = 0; c != EOF; c = fgetc(dictionary_file)) {
        index = get_index(c);

        // Check for the end of string
        if (c == 10) {
            crawler->is_word = true;
            words++;
            i = 0;
        } // Check for beginning of the word
        else if (i == 0) {

            if(!root->alphabet[index]) {
                root->alphabet[index] = malloc(sizeof(node));
                set_alphabet_to_null(root->alphabet[index]);
            }
            crawler = root->alphabet[index];
            i++;
        } // Go to next letter if ptr to current letter exists
        else if (crawler->alphabet[index] != NULL) {
            crawler = crawler->alphabet[index];
        } // Allocate memory (load new letter)
        else {
            crawler->alphabet[index] = malloc(sizeof(node));
            crawler = crawler->alphabet[index];
            set_alphabet_to_null(crawler);
        }
    }

    fclose(dictionary_file);
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word) {
    // Prep
    node *crawler = root;
    int index;

    for(int i = 0; i<LENGTH && *(word+i)!='\0'; i++){
        index = get_index( *(word+i) );

        if(crawler->alphabet[index]) {
            crawler = crawler->alphabet[index];
        } else {
            return false;
        }

    }

    return crawler->is_word;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void) {
    return words;
}



bool unload_node(node *one_node) {

    for(int i = 0; i < 27; i++) {
        if(one_node->alphabet[i]) {
            unload_node(one_node->alphabet[i]);
        }
    }

    free(one_node);
    return true;
}



/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void) {
    node *crawler = root;
    unload_node(crawler);
    return true;
}



