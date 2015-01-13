#include <stdio.h>
#define MAXN 100

/*  Given a stream of numbers, print average of the stream at every point.

    For example, let us consider the stream as 10, 20, 30, ...
    Average of 1 numbers is 10.00
    Average of 2 numbers is 15.00
    Average of 3 numbers is 20.00 */

/* Returns the new average after including x */
float getAvg (int x) {
    static int sum, n;

    sum += x;
    return (((float)sum)/++n);
}

/* Prints average of a stream of numbers */
void streamAvg(float arr[], int n) {
   float avg = 0;
   for(int i = 0; i < n; i++) {
       avg = getAvg(arr[i]);
       printf("Average of %d numbers is %.2f \n", i+1, avg);
   }
}

int main() {
    //float arr[] = {10, 20, 30, 40, 50, 60};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int n;
    float arr[MAXN];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%f", &arr[i]);
    streamAvg(arr, n);

    return 0;
}
