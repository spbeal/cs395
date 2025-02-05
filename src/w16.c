
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