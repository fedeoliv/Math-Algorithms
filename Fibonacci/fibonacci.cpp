#include <stdio.h>
#define LL long long int

/*  Fibonacci using matrix. If we n times multiply the matrix M = {{1,1},{1,0}} to itself
    (in other words calculate power(M, n )), then we get the (n+1)th Fibonacci number as the element
    at row and column (0, 0) in the resultant matrix. */

void multiply(LL F[2][2], LL M[2][2]) {
  LL x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
  LL y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
  LL z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
  LL w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(LL F[2][2], int n) {
    if(n == 0 || n == 1) return;

    LL M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F, F);

    if(n%2 != 0) multiply(F, M);
}

/* function that returns nth Fibonacci number */
LL fib(int n) {
    LL F[2][2] = {{1,1},{1,0}};

    if(n == 0) return 0;
    power(F, n-1);
    return F[0][0];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld", fib(n));
  return 0;
}
