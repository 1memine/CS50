#include <cs50.h>
#include <stdio.h>

int sigma(int);

int main() {
    printf("Sigma of ");
    int a = get_int();
    printf("is %d\n", sigma(a));
}

int sigma(int x) {
    if(x <= 0) {
        return 0;
    } else {
        return x + sigma(x-1);
    }
    
}