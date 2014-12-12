#include <bits/stdc++.h>

int factorial(int n) {
     int product = 1;
     for (int i = 1; i <= n; i++) product *= i;
     return product;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", factorial(x));
    return 0;
}
