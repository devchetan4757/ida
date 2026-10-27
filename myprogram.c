#include <stdio.h>

int main(void) {
    int total = 0;

    for (int i = 0; i <= 9; i++) {
        total += i;

        if (total % 2 == 0) {
            printf("Total is %d, which is even.\n", total);
        } else {
            printf("Total is %d, which is odd.\n", total);
        }
    }

    return 0;
}