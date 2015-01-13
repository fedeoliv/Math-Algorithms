#include <stdio.h>
#include<stdlib.h>

int * anynacci(int *seedArray, int howMany) {
    int *result = malloc (howMany * sizeof (int));
    int i, j, initialCardinality;

    for(i = 0; seedArray[i] != 0; i++);
        initialCardinality = i;

    for(i = 0; i < initialCardinality; i++)
        result[i] = seedArray[i];

    for(i = initialCardinality; i < howMany; i++) {
        result[i] = 0;

        for(j = i - initialCardinality; j < i; j++)
            result[i] += result[j];
    }

    return result;
}

int main () {
    int fibo[] = {1, 1, 0}, tribo[] = {1, 1, 2, 0};
    int tetra[] = {1, 1, 2, 4, 0}, luca[] = { 2, 1, 0 };
    int *fibonacci = anynacci(fibo, 10);
    int *tribonacci = anynacci (tribo, 10);
    int *tetranacci = anynacci (tetra, 10);
    int *lucas = anynacci(luca, 10);
    int i;

    printf ("\nFibonacci\tTribonacci\tTetranacci\tLucas\n");

    for(i = 0; i < 10; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d", fibonacci[i],
        tribonacci[i],tetranacci[i], lucas[i]);

    return 0;
}
