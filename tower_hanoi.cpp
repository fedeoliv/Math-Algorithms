#include <stdio.h>

void solve(int n, char fromrod, char torod, char auxrod) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromrod, torod);
        return;
    }

    solve(n-1, fromrod, auxrod, torod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromrod, torod);
    solve(n-1, auxrod, torod, fromrod);
}

/* Binary solution */
void solve_bin(int n) {
    /* x|x-1: Binary OR Operator copies a bit if it exists in either operand. */
    for(int x = 1; x < (1 << n); x++)
        printf("Move from Peg %i to Peg %i\n",(x&x-1)%3+1,((x|x-1)+1)%3+1);
}

int main() {
    int n; /* Number of disks */
    scanf("%d",&n);

    //solve_bin(n);
    solve(n, 'A', 'C', 'B');  /* A, B and C are names of rods */
    return 0;
}
