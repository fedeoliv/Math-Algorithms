#include<stdio.h>

/*  Function to check if n is a multiple of 3 */
int isMultipleOf3(int n) {
    int odd_count = 0, even_count = 0;

    /*  Make no positive if +n is multiple of 3 then is -n.
        We are doing this to avoid stack overflow in recursion */
    if(n < 0) n = -n;
    if(n == 0) return 1;
    if(n == 1) return 0;

    while(n) {
        /* If odd bit is set then increment odd counter */
        if(n & 1) odd_count++;
        n = n>>1;

        /* If even bit is set then increment even counter */
        if(n & 1) even_count++;
        n = n>>1;
    }

     return isMultipleOf3(abs(odd_count - even_count));
}

int main() {
    int n;
    scanf("%d", &n);

    if(isMultipleOf3(n)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
