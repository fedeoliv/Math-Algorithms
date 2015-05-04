#include <stdio.h>

/*  Given A, B, and C (1 <= A, B, C <= 10000). Find x, y, and z such that:
    1) x + y + z = A
    2) x * y * z = B
    3) x^2 + y^2 + z^2 = C.

    Input: 6 6 14   Output: 1 2 3

    Algorithm:

    - Select the worst equation: x^2 + y^2 + z^2 = C.   (1)
    - Solve it with largest possible values: C = 10000, y = 1 and z = 2 (since y and z must be different).

    x^2 + 1^2 + 2^2 = 10000 ------> x = 100 ------> Range of x = [-100, 100].
    1^2 + y^2 + 2^2 = 10000 ------> y = 100 ------> Range of y = [-100, 100].
    1^2 + 2^2 + z^2 = 10000 ------> z = 100 ------> Range of z = [-100, 100].

    Possible optimization for x:
    2)  x * y * z = B (assuming x = y = z)
        x * x * x = B ------> x = B^(1/3) = 22 ------> Range of x = [-22, 22]. */

int main() {
    int t, A, B, C, solved;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &A, &B, &C);

        solved = 0;

        for(int x = -100; x <= 100; x++)
            if(x*x <= C)
                for(int y = -100; y <= 100; y++)
                    if(x != y && x*x + y*y <= C)
                        for(int z = -100; z <= 100; z++)
                            /* Delete "&& !solved" to print all possible solutions. */
                            if(z != x && z != y &&
                            x + y + z == A && x*y*z == B && x*x + y*y + z*z == C &&
                            !solved) {
                                printf("%d %d %d\n", x, y, z);
                                solved = 1;
                            }

        if(!solved) printf("No solution.\n");
    }

    return 0;
}
