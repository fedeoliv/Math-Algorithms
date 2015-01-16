#include <stdio.h>

/*  Given two polynomials represented by two arrays, write a function that multiplies given two polynomials.

    Input:  A[] = {5, 0, 10, 6}
            B[] = {1, 2, 4}
    Output: prod[] = {5, 10, 30, 26, 52, 24}

    The first input array represents "5 + 0x^1 + 10x^2 + 6x^3"
    The second array represents "1 + 2x^1 + 4x^2"
    And Output is "5 + 10x^1 + 30x^2 + 26x^3 + 52x^4 + 24x^5"
*/

/*  A[] represents coefficients of first polynomial
    B[] represents coefficients of second polynomial
    m and n are sizes of A[] and B[] respectively */
int *multiply(int A[], int B[], int m, int n) {
    int *prod = new int[m+n-1];

    /* Initialize the porduct polynomial */
    for(int i = 0; i<m+n-1; i++) prod[i] = 0;

    /* Take ever term of first polynomial */
    for(int i = 0; i < m; i++) {
        /*  Multiply the current term of first polynomial
            with every term of second polynomial. */
        for(int j = 0; j < n; j++) prod[i+j] += A[i]*B[j];
    }

    return prod;
}

void printPoly(int poly[], int n) {
    for(int i = 0; i < n; i++) {
       printf("%d", poly[i]);
       if(i != 0) printf("x^%d", i);
       if(i != n-1) printf(" + ");
    }
    printf("\n");
}

int main() {
    int A[] = {5, 0, 10, 6};
    int B[] = {1, 2, 4};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);

    printf("First polynomial: ");
    printPoly(A, m);

    printf("Second polynomial: ");
    printPoly(B, n);

    int *prod = multiply(A, B, m, n);

    printf("Product: ");
    printPoly(prod, m+n-1);

    return 0;
}
