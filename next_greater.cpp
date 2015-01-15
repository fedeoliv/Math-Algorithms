#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*  Given a number n, find the smallest number that has same set of digits as n and is greater than n.
    If x is the greatest possible number with its set of digits, then print “Not possible”.

    Input:  n = "218765"
    Output: "251678"

    Input:  n = "1234"
    Output: "1243 */

int main() {
    string input;
    cin >> input;

    if(next_permutation(input.begin(), input.end()))
        cout << input << endl;
    else cout << "Not possible" << endl;

    return 0;
}
