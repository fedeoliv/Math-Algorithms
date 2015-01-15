#include <stdio.h>
#define MAXN 100

/*  Given a polynomial and a value of x, find the value of polynomial for a given value of x.
    Example: For x = 3, evaluate value of 2x^3 - 6x^2 + 2x - 1.
    Input: poly[] = {2, -6, 2, -1}, x = 3
    Output: 5
*/

/* Returns the value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1] */
int horner(int poly[], int n, int x) {
    int result = poly[0];   /* Initialize result */

    /* Evaluate value of polynomial using Horner's method */
    for(int i = 1; i < n; i++) result = result*x + poly[i];
    return result;
}

int main() {
    int n, x;
    int poly[MAXN];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &poly[i]);
    scanf("%d", &x);

    printf("%d", horner(poly, n, x));
    return 0;
}
