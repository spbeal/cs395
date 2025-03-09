/*********************************************
 * Id: beal6782
 * 
 * Quick Hull
 * 
 * Implement an algorithm for finding a Convex Hull
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
   int x;
   int y;
} Point;

// find the side of a point relative to a line
int find_side(Point p1, Point p2, Point p) {
   int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
   return (val > 0) - (val < 0);
}

// find the distance from a point to a line
int distance(Point p1, Point p2, Point p) {
   return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

void quick_hull(Point points[], int n, Point p1, Point p2, int side, Point hull[], int *hull_size) {
   int max_dist = 0, index = -1;
   for (int i = 0; i < n; i++) {
       int dist = distance(p1, p2, points[i]);
       if (find_side(p1, p2, points[i]) == side && dist > max_dist) {
           max_dist = dist;
           index = i;
       }
   }

   if (index == -1) {
       hull[(*hull_size)++] = p1;
       return;
   }

   quick_hull(points, n, points[index], p1, -find_side(points[index], p1, p2), hull, hull_size);
   quick_hull(points, n, points[index], p2, -find_side(points[index], p2, p1), hull, hull_size);
}

void convex_hull(Point points[], int n) {
   if (n < 3) {
       printf("Convex hull not possible\n");
       return;
   }
   
   int min_index = 0, max_index = 0;
   for (int i = 1; i < n; i++) {
       if (points[i].x < points[min_index].x || (points[i].x == points[min_index].x && points[i].y < points[min_index].y))
         min_index = i;
       if (points[i].x > points[max_index].x || (points[i].x == points[max_index].x && points[i].y > points[max_index].y))
         max_index = i;
   }
   
   Point hull[n];
   int hull_size = 0;
   
   quick_hull(points, n, points[min_index], points[max_index], 1, hull, &hull_size);
   quick_hull(points, n, points[min_index], points[max_index], -1, hull, &hull_size);
   
   // Sort points in clockwise order
   printf("The points in Convex Hull are:\n");
   for (int i = 0; i < hull_size; i++) {
       printf("(%d, %d) ", hull[i].x, hull[i].y);
   }
   printf("(%d, %d)\n", hull[0].x, hull[0].y);
}

int main (int argc, char *argv[])
{
   if (argc < 5)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int n = (argc - 1) / 2;
   Point points[n];
   for (int i = 0; i < n; i++)
   {
      points[i].x = atoi(argv[i*2 + 1]);
      points[i].y = atoi(argv[i*2 + 2]); // not out of bounds because argc is n+1
      // printf("%d %d ", points[i].x, points[i].y);
   }
   convex_hull(points, n);
}
   // memset(convex_hull, 0, half_n);

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