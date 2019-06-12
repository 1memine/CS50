#include <stdio.h>
#include <math.h>
#include <cs50.h>


int main() {
    int coins = 0;
    float change = round(100*get_float("Sup! How much is owed?\n")); // округляем
//    change = round(change*100);
// можно сразу округлить как в строке 7, можно в два шага для большей читабельности кода

    while(change >= 25) {
        change -= 25;
        coins++;
    }

    while(change >= 10) {
        change -= 10;
        coins++;
    }

    while(change >= 5) {
        change -= 5;
        coins++;
    }

    while(change >= 1) {
        change -= 1;
        coins++;
    }

    printf("%i\n", coins);

}