#include <stdio.h>

/*  Given a 3x3 board with 8 tiles (every tile has one number from 1 to 8) and one empty space.
    If inversion count is even, it's possible to solve.

    For 15-puzzle, is solvable if:
    ( (grid width odd) && (#inversions even) )  ||
    ( (grid width even) && ((blank on odd row from bottom) == (#inversions even)) )*/

int getInvCount(int arr[]) {
    int inv_count = 0;
    for(int i = 0; i < 9 - 1; i++)
        for(int j = i+1; j < 9; j++)
             /* Value 0 is used for empty space */
             if(arr[j] && arr[i] &&  arr[i] > arr[j]) inv_count++;
    return inv_count;
}

/* Function returns true if given 8 puzzle is solvable. */
bool isSolvable(int puzzle[3][3]) {
    /*  Count inversions in given 8 puzzle */
    int invCount = getInvCount((int *)puzzle);

    /*  Return true if inversion count is even. */
    return (invCount % 2 == 0);
}

int main() {
    int puzzle[3][3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) scanf("%d", &puzzle[i][j]);

    if(isSolvable(puzzle)) printf("Yes\n");
    else printf("No\n");

/*
  int puzzle[3][3] =  {{1, 8, 2},
                      {0, 4, 3},  // Value 0 is used for empty space
                      {7, 6, 5}};
  isSolvable(puzzle)? cout << "Solvable":
                      cout << "Not Solvable";
*/
  return 0;
}
