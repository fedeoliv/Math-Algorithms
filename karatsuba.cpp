#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;
typedef long long LL;

LL a[MAXN], b[MAXN], c[2*MAXN];

void mul(LL a[], int an, LL b[], int bn, LL c[], int &cn) {
    if (an < bn) { swap(an, bn); swap(a, b); }
    if (bn == 0) { cn = 0; return; }
    if (bn == 1) { cn = an; REP(i, cn) c[i] = a[i] * b[0]; return; }
    cn = an + bn - 1;
    memset(c, 0, sizeof(c[0])*cn);

    int m = (an+1)/2, n = min(m, bn), tn1, tn2, tn3;
    LL *al = a, *ah = a+m, *bl = b, *bh = b+m;
    LL tmp1[2*m], tmp2[2*m], tmp3[2*m];
    REP(i, m) tmp1[i] = al[i] + (i < an-m ? ah[i] : 0);
    REP(i, n) tmp2[i] = bl[i] + (i < bn-n ? bh[i] : 0);
    mul(tmp1, m, tmp2, n, tmp3, tn3);     // = (al + ah)(bl + bh)
    mul(al, m, bl, n, tmp1, tn1);         // = al bl
    mul(ah, an-m, bh, bn-n, tmp2, tn2);   // = ah bh

    REP(i, tn1) { c[i] += tmp1[i]; c[i+m] -= tmp1[i]; }
    REP(i, tn2) { c[i+2*m] += tmp2[i]; c[i+m] -= tmp2[i]; }
    REP(i, tn3) c[i+m] += tmp3[i];
}

int main() {
    //int an = N, bn = N-1, cn;
    //REP(i, an) a[i] = rand();
    //REP(i, bn) b[i] = rand();
    //mul(a, an, b, bn, c, cn);
    LL result = 0;
    int cn;

    a[0] = 9999999;
    b[0] = 123454764376;

    mul(a, 1, b, 1, c, cn);  // 1 = number of values in a[] and b[].
    REP(i, cn) result += c[i];
    printf("%lld\n", result);

    return 0;
}
