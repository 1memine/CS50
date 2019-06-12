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

Node *dict_root[HASH_TABLE_SIZE];
unsigned dict_size = 0;

/**
 * Returns just an index of a next word
 */
int hash(char word[]) {
    unsigned key = word[0];
    for (int i = 0, l = strlen(word); i < l; i++) {
        key += word[i];
        key *= 41;
    }
    return key%HASH_TABLE_SIZE;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary) {

    // Open dictionary file and check if it exists
    FILE* dictionary_fp = fopen(dictionary, "r");
    if(!dictionary_fp) {
        printf("Couldn't open dictionary file.\n");
        return false;
    }

    // Prepare to get all words char by char
    char buffer[LENGTH+1];
    int i = 0, c = fgetc(dictionary_fp), index;

    // Get every char in textfile
    while (c != EOF) {
        // Check for end string
        if (c != 10) {
            buffer[i] = c;
            i++;
        } else {
            // End string
            buffer[i] = '\0';

            // Prepare node for insertion to hash table
            Node *new_node = malloc(sizeof(Node));
            strcpy(new_node->word, buffer);
            new_node->next = NULL;
            index = hash(buffer);


            if (!dict_root[index]) { // Check if first bucket with "index" is empty
                dict_root[index] = new_node;
            } else {
                Node *crawler = dict_root[index];
                // Find pointer to last element
                while(crawler->next) {
                    crawler = crawler->next;
                } // crawler is a pointer to last element of LL
                crawler->next = new_node;
            }
            dict_size++;
            i = 0;
        }
        c = fgetc(dictionary_fp);

    }

    // Close file pointer
    fclose(dictionary_fp);

    // Success
    return true;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word) {

    char* temp = malloc(LENGTH+1); // word + '\0'
    strcpy(temp, word);
    for(int i = 0; i < strlen(temp); i++) {
        *(temp+i) = tolower(*(temp+i));
    }

    Node *crawler = dict_root[hash(temp)];

    while(crawler) {
        if(strcmp(crawler->word, temp) == 0) {
            free(temp);
            return true;
        } else {
            crawler = crawler->next;
        }
    }

    free(temp);
    return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void) {
    return dict_size;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void) {

    Node *cursor, *temp;

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        cursor = dict_root[i];

        while(cursor) {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

    }

    return true;
}
