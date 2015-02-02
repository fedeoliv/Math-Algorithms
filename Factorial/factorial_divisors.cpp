#include <stdio.h>
#define MAX_N 50000
#define MOD 1000000007

int prime[MAX_N+1];

/*  Given a number, find the total number of divisors of the factorial of the number.
    For n = 2: 2 divisors
    For n = 4: 8 divisors and so on. */

void sieve() {
    int i, j;
    for(i = 2; i <= MAX_N; i++) prime[i] = 1;
    for(i = 2; i*i <= MAX_N; i++)
        if(prime[i])
            for (j = i*i; j <= MAX_N; j+=i) prime[j] = 0;
}

int main() {
    freopen("a.txt", "r", stdin);

    int i, j, t, n;
    long long int div;  /* Number of divisors */
    long int e, d;

    sieve();

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        div = 1;

        for(i = 2; i <= n; i++)
            if(prime[i]) {
                e = 1, d = i;

                while (d <= n) {
                    e += (n/d);
                    d *= i;
                }

                div = div*e;
                if(div >= MOD) div %= MOD;
            }

        printf("%lld\n", div);
    }

    return 0;
}
