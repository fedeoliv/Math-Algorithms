#include <bits/stdc++.h>
#define BASE 14
#define MAXN 100

/* Add two numbers in base N */

/*  Function to get numeral for a value. */
char getNumeral(int val) {
    if(val >= 0 && val <= 9) return (val + '0');
    if(val >= 10 && val <= BASE) return (val + 'A' - 10);

    /* If we reach this line caller is giving invalid no. so we assert and fail */
    assert(0);
}

/*  Function to get value of a numeral. */
int getNumeralValue(char num) {
    if(num >= '0' && num <= '9') return (num - '0');
    if(num >= 'A' && num <= 'D') return (num - 'A' + 10);

    /* If we reach this line caller is giving invalid character so we assert and fail */
    assert(0);
}

/* Function to add two numbers in base N*/
char *sumBase(char *num1,  char *num2) {
    int a = strlen(num1);
    int b = strlen(num2);
    int nml1, nml2, res_nml;
    char *res;
    bool carry = false;

    if(a != b) {
        printf("Function doesn't support numbers of different"
            " lengths. If you want to add such numbers then"
            " prefix smaller number with required no. of zeroes\n");
        assert(0);
    }

    /*  Note the size of the allocated memory is one more than i/p lenghts
        for the cases where we have carry at the last like adding D1 and A1 */
    res = (char *)malloc(sizeof(char)*(a + 1));

    /* Add all numerals from right to left */
    for(int i = a-1; i >= 0; i--) {
        /* Get decimal values of the numerals of i/p numbers*/
        nml1 = getNumeralValue(num1[i]);
        nml2 = getNumeralValue(num2[i]);

        /* Add decimal values of numerals and carry */
        res_nml = carry + nml1 + nml2;

        /* Check if we have carry for next addition of numerals */
        if(res_nml >= BASE) {
            carry = 1;
            res_nml -= BASE;
        } else carry = 0;

        res[i+1] = getNumeral(res_nml);
    }

    /*  If there is no carry after last iteration then result should not include
        0th character of the resultant string */
    if(carry == 0) return (res + 1);

    /*  If we have carry after last iteration then result should include 0th character */
    res[0] = '1';
    return res;
}

int main() {
    //char *num1 = "DC2", *num2 = "0A3";
    char a[MAXN], b[MAXN];
    int x;

    scanf("%s %s", a, b);

    char* res = sumBase(a, b);
    printf("Result is %s\n", res);

    return 0;
}
