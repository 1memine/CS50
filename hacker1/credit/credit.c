#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){
    long long cc = get_long_long("Number: ");
    int sum = 0; //type = 0;

/*
    if( cc > 34*(pow(10,13)) && cc < 38*pow(10,13)-1 ) {
        type = 1;       //cc amex
    } else if( cc > 4*pow(10,15) && cc < 5*pow(10,15)-1 ) {
        type = 2;       //cc visa
    } else if( cc > 51*pow(10,14) && cc < 56*pow(10,14)-1 ) {
        type = 3;       //cc ms
    }
*/
    while(cc != 0) {
        sum += cc%10;
        cc /= 10;

        if ( 2*(cc%10) < 10 ) {
            sum += 2*(cc%10);
        } else {
            sum += 1+(2*(cc%10))%10;
        }
        cc /= 10;
    }

    if (sum%10 != 0) {
        printf("Not good\n");
    } else {
        printf("Good\n");
    }

/*
    switch(type) {
        case 1:
        printf("AMEX\n");
        break;

        case 2:
        printf("VISA\n");
        break;

        case 3:
        printf("MASTERCARD\n");
        break;

        default:
        printf("INVALID\n");
        break;
    }
*/
    printf("\nsum: %d", sum);
}