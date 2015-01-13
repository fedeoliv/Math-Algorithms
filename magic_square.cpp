#include<stdio.h>
#include<string.h>

/*  A magic square of order n is an arrangement of n^2 numbers, usually distinct integers, in a square,
    such that the n numbers in all rows, all columns, and both diagonals sum to the same constant.
    The constant sum in every row, column and diagonal is called the magic constant or magic sum, M.
    The magic constant of a normal magic square depends only on n and has the following value:
    M = n(n^2+1)/2 */

/* A function to generate odd sized magic squares */
void generateSquare(int n) {
    int magicSquare[n][n];

    memset(magicSquare, 0, sizeof(magicSquare));

    /* Initialize position for 1 */
    int i = n/2, j = n-1;

    /* One by one put all values in magic square */
    for(int num = 1; num <= n*n;) {
        if (i==-1 && j==n) {
            j = n-2;
            i = 0;
        } else {
            if(j == n) j = 0;
            if(i < 0) i = n-1;
        }

        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else magicSquare[i][j] = num++;

        j++; i--;
    }

    printf("Sum of each row or column: %d\n\n", n*(n*n+1)/2);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) printf("%d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    generateSquare(n);
    return 0;
}
