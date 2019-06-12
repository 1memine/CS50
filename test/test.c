#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/**

int main(int argc, char *argv[]) {
    char *str2 = "012*456*89\r\n";
    int length = strlen(str2);
    char *str = malloc (sizeof(char) * length);
    strcpy(str, str2);
    if ( str[length-2] == '\r' && str[length-1] == '\n') {
        printf("yes\n");
        printf("%c\n", str[length+223]);
    }



}
*/

int main () {
    int a[2];
    a[1] = 1; a[0] = 0;
    printf("%d\n", *(a+2) );
}
