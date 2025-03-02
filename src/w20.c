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
//#include <string.h>

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
BFS or DFS bipartite graph determinor.

A graph is said to be bipartite if all its vertices can be partitioned into two 
disjoint subsets X and Y so that every edge connects a vertex in X with a vertex 
in Y. (One can also say that a graph is bipartite if its vertices can be colored 
in two colors so that every edge has its vertices colored in different colors; 
such graphs are also called 2-colorable.) 

Do either A or B.

A. Design a DFS-based algorithm for checking whether a graph is bipartite. Thus, 
let F be a DFS forest of a graph. It is not difficult to see that F is 
2-colorable if and only if there is no back edge connecting two vertices both on 
odd levels or both on even levels. It is this property that a DFS traversal 
needs to verify. Note that a DFS traversal can mark vertices as even or odd when 
it reaches them for the first time.

B.Design a BFS-based algorithm for checking whether a graph is bipartite. Thus, 
similarly to part (A), a graph is 2-colorable if and only if its BFS forest has 
no cross edge connecting.

*/