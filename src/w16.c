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
   int max_dist = 0;
   int index = -1;
   
   // Find the point with maximum distance from the line
   for (int i = 0; i < n; i++) {
       int dist = distance(p1, p2, points[i]);
       if (find_side(p1, p2, points[i]) == side && dist > max_dist) {
           max_dist = dist;
           index = i;
       }
   }

   // If no point is found, add p1 to hull
   if (index == -1) {
       hull[(*hull_size)++] = p1;
       hull[(*hull_size)++] = p2;
       return;
   }

   // Recursively find points on both sides of the line
   Point C = points[index];
   quick_hull(points, n, C, p1, -find_side(C, p1, p2), hull, hull_size);
   quick_hull(points, n, C, p2, -find_side(C, p2, p1), hull, hull_size);
}

int compare_upper(const void *a, const void *b) {
   Point *p1 = (Point *) a;
   Point *p2 = (Point *) b;
   if (p1->x != p2->x) {
       return (p1->x > p2->x) ? 1 : -1;
   } else {
       return (p1->y > p2->y) ? 1 : -1;
   }
}

int compare_lower(const void *a, const void *b) {
   Point *p1 = (Point *) a;
   Point *p2 = (Point *) b;
   if (p1->x != p2->x) {
       return (p2->x > p1->x) ? 1 : -1;
   } else {
       return (p2->y > p1->y) ? 1 : -1;
   }
}

void convex_hull(Point points[], int n) {
   if (n < 3) {
       printf("Convex hull not possible\n");
       return;
   }
   
   // Find leftmost and rightmost points
   int min_index = 0, max_index = 0;
   for (int i = 1; i < n; i++) {
       if (points[i].x < points[min_index].x || 
           (points[i].x == points[min_index].x && points[i].y < points[min_index].y))
           min_index = i;
       if (points[i].x > points[max_index].x || 
           (points[i].x == points[max_index].x && points[i].y > points[max_index].y))
           max_index = i;
   }
   
   Point *hull = (Point *)malloc(n * sizeof(Point));
   if (hull == NULL) {
       printf("Memory allocation failed\n");
       return;
   }
   
   int hull_size = 0;
   
   // Find points on both sides of the line
   quick_hull(points, n, points[min_index], points[max_index], 1, hull, &hull_size);
   quick_hull(points, n, points[min_index], points[max_index], -1, hull, &hull_size);
   
   // Remove duplicates
   Point unique_hull[hull_size];
   int unique_size = 0;
   for (int i = 0; i < hull_size; i++) {
       int duplicate = 0;
       for (int j = 0; j < unique_size; j++) {
           if (hull[i].x == unique_hull[j].x && hull[i].y == unique_hull[j].y) {
               duplicate = 1;
               break;
           }
       }
       if (!duplicate) {
           unique_hull[unique_size++] = hull[i];
       }
   }

   Point p_min = points[min_index];
   Point p_max = points[max_index];

   // Split into upper and lower
   Point upper[unique_size], lower[unique_size];
   int upper_count = 0, lower_count = 0;

   for (int i = 0; i < unique_size; i++) {
       Point p = unique_hull[i];
       int side = find_side(p_min, p_max, p);
       if (side >= 0) {
           upper[upper_count++] = p;
       }
       if (side <= 0) {
           lower[lower_count++] = p;
       }
   }

   qsort(upper, upper_count, sizeof(Point), compare_upper);
   qsort(lower, lower_count, sizeof(Point), compare_lower);

   Point sorted_hull[unique_size + 1];
   int sorted_count = 0;

   for (int i = 0; i < upper_count; i++) {
       if (sorted_count == 0 || upper[i].x != sorted_hull[sorted_count-1].x || upper[i].y != sorted_hull[sorted_count-1].y) {
           sorted_hull[sorted_count++] = upper[i];
       }
   }

   for (int i = 0; i < lower_count; i++) {
       int found = 0;
       for (int j = 0; j < sorted_count; j++) {
           if (lower[i].x == sorted_hull[j].x && lower[i].y == sorted_hull[j].y) {
               found = 1;
               break;
           }
       }
       if (!found) {
           sorted_hull[sorted_count++] = lower[i];
       }
   }

   sorted_hull[sorted_count] = sorted_hull[0];
   sorted_count++;

   printf("The points in Convex Hull are:\n");
   for (int i = 0; i < sorted_count; i++) {
       printf("(%d, %d) ", sorted_hull[i].x, sorted_hull[i].y);
   }
   printf("\n");
   
   free(hull);
}

int main(int argc, char *argv[]) {
   if (argc < 5) {
      printf("%s 1 2 3 4 5 6 7 8\n", argv[0]);
      exit(1);
   }

   int n = (argc - 1) / 2;
   Point *points = (Point *)malloc(n * sizeof(Point));
   if (points == NULL) {
       printf("Memory allocation failed\n");
       exit(1);
   }

   for (int i = 0; i < n; i++) {
      points[i].x = atoi(argv[i*2 + 1]);
      points[i].y = atoi(argv[i*2 + 2]);
   }
   
   convex_hull(points, n);
   free(points);
   return 0;
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