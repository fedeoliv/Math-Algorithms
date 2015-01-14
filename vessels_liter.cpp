#include <stdio.h>
#include <algorithm>
#define MAXLITRE 1
using namespace std;

/*  There are two vessels of capacities ‘a’ and ‘b’ respectively. We have infinite water supply.
    Give an efficient algorithm to make exactly 1 litre of water in one of the vessels.
    You can throw all the water from any vessel any point of time. Assume that ‘a’ and ‘b’ are Coprimes.

    Sample run of the Algo for V1 with capacity 3 and V2 with capacity 7
    1. Fill V1:                               V1 = 3, V2 = 0
    2. Transfer from V1 to V2, and fill V1:   V1 = 3, V2 = 3
    2. Transfer from V1 to V2, and fill V1:   V1 = 3, V2 = 6
    3. Transfer from V1 to V2, and empty V2:  V1 = 2, V2 = 0
    4. Transfer from V1 to V2, and fill V1:   V1 = 3, V2 = 2
    5. Transfer from V1 to V2, and fill V1:   V1 = 3, V2 = 5
    6. Transfer from V1 to V2, and empty V2:  V1 = 1, V2 = 0
    7. Stop as V1 now contains 1 litre.

    Note that V2 was made empty in steps 3 and 6 because it became full */

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

/* Class to represent a Vessel */
class Vessel {
    /* A vessel has capacity, and current amount of water in it */
    int capacity, current;
    public:
        /*  Constructor: initializes capacity as given, and current as 0 */
        Vessel(int capacity) { this->capacity = capacity; current = 0; }

        /*  The main function to fill MAXLITRE in this vessel. Capacity of V2
            must be greater than this vessel and two capacities must be co-prime */
        void makeLiter(Vessel &V2);

        /*  Fills vessel with given amount and returns the amount of water transferred to it.
            If the vessel becomes full, then the vessel is made empty. */
        int transfer(int amount);
};

/*  The main function to fill one litre in this vessel.
    Capacity of V2 must be greater than this vessel and two capacities must be coprime */
void Vessel:: makeLiter(Vessel &V2) {
    /* solution exists iff a and b are co-prime */
    if(gcd(capacity, V2.capacity) != 1) return;

    while(current != MAXLITRE) {
        /* fill A (smaller vessel) */
        if(current == 0) current = capacity;

        printf("Vessel 1: %d   Vessel 2: %d\n", current, V2.current);

        /*  Transfer water from V1 to V2 and reduce current of V1 by
            the amount equal to transferred water */
        current = current - V2.transfer(current);
    }

    /* Finally, there will be 1 litre in vessel 1 */
    printf("Vessel 1: %d   Vessel 2: %d\n", current, V2.current);

}

/*  Fills vessel with given amount and returns the amount of water transferred to it.
    If the vessel becomes full, then the vessel is made empty */
int Vessel::transfer(int amount) {
    /* If the vessel can accommodate the given amount */
    if(current + amount < capacity) {
        current += amount;
        return amount;
    }

    /*  If the vessel cannot accommodate the given amount, then
        store the amount of water transferred */
    int transferred = capacity - current;

    /*  Since the vessel becomes full, make the vessel empty to be filled again */
    current = 0;

    return transferred;
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    if(a > b) swap(a, b);   /* a must be smaller than b */

    Vessel V1(a), V2(b);
    V1.makeLiter(V2);

    return 0;
}
