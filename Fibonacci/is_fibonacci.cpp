#include <stdio.h>
#include <math.h>

/* Check if n is a Fibonacci number */

bool isPerfectSquare(int x) {
    int s = sqrt(x);
    return (s*s == x);
}

/*  Returns true if n is a Fibinacci Number, else false */
bool isFibonacci(int n) {
    /*  n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both is a perferct square */
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}

int main() {
    int n;
    scanf("%d", &n);

    if(isFibonacci(n)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
