/*********************************************
 * Id: beal6782
 * 
 * Russian Peasant Multiplication
 * 
 * Implement an algorithm for russian peasant multiplcation
 * n/2 * 2m for even
 * n-1/2 * 2m + m for odd
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(int n, int m);
void printMul(int n, int m);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   multiply(x,y);
}
/*
Quick Hull 

Implement the Quick Hull algorithm section 5.5.

The input is a set of command line integers representing each point (the x coordinate followed by the y coordinate).

The output is the set of points in the convex hull order listed clockwise.
Hint: List the top arch in increasing x coordinates and the bottom arch in decreasing x coordinates.
      Break ties with the Y coordinate.

For example:

./quickHull 0 3 1 1 2 2 4 4 0 0 1 2 3 1 3 3
The points in Convex Hull are:
(0, 0) (0, 3) (4, 4) (3, 1) (0, 0)

./quickHull 0 0 0 4 -4 0 5 0 0 -6 1 0
The points in Convex Hull are:
(-4, 0) (0, 4) (5, 0) (0, -6) (-4, 0)

Compile errors: 
0: file not recognized: File truncated
collect2: error: ld returned 1 exit status
*/