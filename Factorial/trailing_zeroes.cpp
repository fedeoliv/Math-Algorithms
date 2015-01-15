#include <stdio.h>

/* Given an integer n, write a function that returns count of trailing zeroes in n!. */

int findTrailingZeros(int  n) {
    int cnt = 0;
    // Keep dividing n by powers of 5 and update count
    for(int i = 5; n/i >= 1; i *= 5) cnt += n/i;
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", findTrailingZeros(n));
    return 0;
}
