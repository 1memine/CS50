#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} LinkedList;

void assign(int, LinkedList*, LinkedList*);

int main() {
    LinkedList *list = malloc(sizeof(LinkedList)), *node = malloc(sizeof(LinkedList));

    assign(5, list, node);
    assign(3, node, NULL);

    printf("%d\n", node->value);

    free(list);
    free(node);wget http://cdn.cs50.net/2015/fall/psets/5/pset5/pset5.zip
}

void assign(int a, LinkedList *node, LinkedList *next) {
    node->value = a;
    node->next = next;
}