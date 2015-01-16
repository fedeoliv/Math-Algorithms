#include <stdio.h>

/*  Given a number 'n', find the smallest number 'p' such that if we multiply all digits of 'p', we get 'n'.

    Input:  n = 36
    Output: p = 49
    Note that 4*9 = 36 and 49 is the smallest such number */

void getSmallest(int n) {
	if(n < 10) {
        printf("%d\n", n+10);
        return;
	}

	int output = 0, m = 1;

	for(int i = 9; i > 1; i--) {  /* Only find factor between 2 to 9 */
		if(n % i == 0) {
			output += (m*i);    /* If any such i then add to output */
			m = m*10;
			n = n/i;    /* Update new n */
			i = 9;
		}
	}

	if(n == 1) printf("%d\n", output);
	else printf("Not possible\n");
}

int main() {
	int n;
	scanf("%d", &n);
	getSmallest(n);
	return 0;
}
