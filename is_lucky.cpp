#include <bits/stdc++.h>

/*  Function to say whether this number is lucky or not.

    Take the set of integers:
    1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,...

    First, delete every second number, we get following reduced set:
    1,3,5,7,9,11,13,15,17,19,...

    Now, delete every third number, we get:
    1, 3, 7, 9, 13, 15, 19,...

    Continue this process indefinitely. Any number that does NOT get deleted
    due to above process is called “lucky”.

    Therefore, set of lucky numbers is 1, 3, 7, 13,... */

bool isLucky(int n) {
    int next_pos = n;

    for(int i = 2; i <= next_pos; ++i) {
        if(next_pos % i == 0) return false;

        /* Next position = (current position - number of positions reduced in this iteration) */
        next_pos -= next_pos/i;
    }

    /*  If we have reached here then n is not deleted in any of the deletion process.
        Therefore n is lucky number*/
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    if(isLucky(n)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
