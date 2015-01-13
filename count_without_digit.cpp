#include <stdio.h>
#define DIGIT 3

/* Count how many numbers are in range from 1 to n and don't contain 3 as a digit */

int count(int n) {
    /*  Base cases (Assuming n is not negative) */
    if(n < DIGIT) return n;
    if(n >= DIGIT && n < 10) return n-1;

    /*  Calculate 10^(d-1) (10 raise to the power d-1) where d is number of digits in n.*/
    int po = 1;
    while(n/po > 9) po = po*10;

    int msd = n/po; /* Find the most significant digit */

    if(msd != DIGIT) return count(msd)*count(po - 1) + count(msd) + count(n%po);
    else return count(msd*po - 1);
}

int main() {
    printf("%d\n", count(578));
    return 0;
}
