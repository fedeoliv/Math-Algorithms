#include <iostream>
#include <algorithm>
using namespace std;

/*  Find lexicographic minimum in a circular array.
    For example: BCABDADAB, the lexicographic minimum is ABBCABDAD. */

/*  This functionr return lexicographically minimum rotation of str */
string minLexRotation(string str) {
    /* Find length of given string */
    int n = str.length();

    /* Create an array of strings to store all rotations */
    string arr[n];

    /* Create a concatenation of string with itself */
    string concat = str + str;

    /*  One by one store all rotations of str in array.
        A rotation is obtained by getting a substring of concat */
    for(int i = 0; i < n; i++) arr[i] = concat.substr(i, n);
    sort(arr, arr+n);   /* Sort all rotations */

    /* Return the first rotation from the sorted array */
    return arr[0];
}

int main() {
    cout << minLexRotation("GEEKSFORGEEKS") << endl;
    cout << minLexRotation("GEEKSQUIZ") << endl;
    cout << minLexRotation("BCABDADAB") << endl;
}
