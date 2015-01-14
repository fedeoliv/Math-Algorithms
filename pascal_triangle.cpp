#include <stdio.h>
typedef long long int LL;

/*  Pascal's triangle is a triangular array of the binomial coefficients.
    Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle.
    Following are the first 6 rows of Pascal's Triangle:
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1 */

void printPascal(int n) {
    for(int line = 1; line <= n; line++) {
        LL C = 1;  /* used to represent C(line, i) */

        for (int i = 1; i <= line; i++) {
            printf("%lld ", C);  /* The first value in a line is always 1 */
            C = C * (line - i) / i;
        }
        printf("\n");
    }
}

int main() {
    printPascal(10);
}
