#include <stdio.h>
typedef unsigned long long int ULL;
typedef unsigned int UINT;

/*  Returns value of Binomial Coefficient C(n, k) */
ULL binomialCoeff(UINT n, UINT k) {
    ULL res = 1;

    /*  Since C(n, k) = C(n, n-k) */
    if(k > n - k) k = n - k;

    /*  Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] */
    for(int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

/*  Binomial coefficient based function to find nth catalan number in O(n) time */
ULL catalan(UINT n) {
    /*  Calculate value of 2nCn */
    ULL c = binomialCoeff(2*n, n);

    /*  return 2nCn/(n+1) */
    return c/(n+1);
}

int main() {
    UINT n;
    scanf("%u", &n);
    printf("%llu ", catalan(n));
    return 0;
}
