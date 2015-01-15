#include <bits/stdc++.h>
#define MAX 50
using namespace std;

/*  MS Excel columns has a pattern like A, B, C, ... , Z, AA, AB, AC,... ,AZ, BA, BB, ...ZZ, AAA, AAB ... etc.
    In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.
    Given a column number, find its corresponding Excel column name. For example:
    26 -> Z
    51 -> AY */

char *strrev(char *str) {
      char *p1, *p2;

      if(! str || ! *str) return str;
      for(p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
      }

      return str;
}

/* Function to print Excel column name for a given column number */
void printString(int n) {
    char str[MAX];  /* Store result (Excel column name) */
    int i = 0;      /* Store current index in str which is result */

    while(n > 0) {
        int rem = n % 26; /* Find remainder */

        /*  If remainder is 0, then a 'Z' must be there in output */
        if(rem == 0) {
            str[i++] = 'Z';
            n = (n/26)-1;
        } else {    /* If remainder is non-zero */
            str[i++] = (rem-1) + 'A';
            n = n/26;
        }
    }

    str[i] = '\0';

    /*  Reverse the string and print result */
    printf("%s\n", strrev(str));
    return;
}

int main() {
    int n;
    scanf("%d", &n);

    printString(n);
    return 0;
}
