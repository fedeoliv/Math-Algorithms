#include <stdio.h>

/*  Add two polynomials.

    Input:  A[] = {5, 0, 10, 6}
            B[] = {1, 2, 4}
    Output: sum[] = {5, 10, 30, 26, 52, 24}

    The first input array represents "5 + 0x^1 + 10x^2 + 6x^3"
    The second array represents "1 + 2x^1 + 4x^2"
    And Output is "6 + 2x^1 + 14x^2 + 6x^3"*/

int max(int m, int n) {  return (m > n)? m: n; }

/*  A[] represents coefficients of first polynomial
    B[] represents coefficients of second polynomial
    m and n are sizes of A[] and B[] respectively */
int *add(int A[], int B[], int m, int n) {
   int size = max(m, n);
   int *sum = new int[size];

   /* Initialize the porduct polynomial */
   for(int i = 0; i < m; i++) sum[i] = A[i];

   /* Take ever term of first polynomial */
   for(int i = 0; i < n; i++) sum[i] += B[i];

   return sum;
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

    int *sum = add(A, B, m, n);
    int size = max(m, n);

    printf("Sum: ");
    printPoly(sum, size);

    return 0;
}
