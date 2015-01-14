#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
#define MAXN 100

/*  Given a string, find its rank among all its permutations sorted lexicographically.
    For example, rank of "abc" is 1, rank of “acb” is 2, and rank of "cba" is 6. */

/*  A utility function to find factorial of n */
int fact(int n) {
    return (n <= 1)? 1 :n * fact(n-1);
}

/*  Construct a count array where value at every index
    contains count of smaller characters in whole string */
void increase_count(int* count, char* str) {
    for(int i = 0; str[i]; ++i) ++count[str[i]];
    for(int i = 1; i < MAX_CHAR; ++i) count[i] += count[i-1];
}

/*  Removes a character ch from count[] array constructed by increase_count() */
void updatecount (int* count, char ch) {
    for(int i = ch; i < MAX_CHAR; ++i) --count[i];
}

/*  A function to find rank of a string in all permutations of characters */
int findRank (char* str) {
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1, i;
    int count[MAX_CHAR] = {0};  /* All elements of count[] are initialized with 0 */

    /*  Populate the count array such that count[i] contains count of
        characters which are present in str and are smaller than i */
    increase_count( count, str );

    for(i = 0; i < len; ++i) {
        mul /= len - i;

        /*  Count number of chars smaller than str[i] fron str[i+1] to str[len-1] */
        rank += count[ str[i] - 1] * mul;

        /* Reduce count of characters greater than str[i] */
        updatecount (count, str[i]);
    }

    return rank;
}

int main() {
    char str[MAXN];
    scanf("%s", str);
    printf("%d", findRank(str));
    return 0;
}
