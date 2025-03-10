/*********************************************
 * Id: beal6782
 * 
 * DFS or BFS bipartite graph determinor
 * 
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void engine( int x, int y, int n, char arr[])
{

}

int main (int argc, char *argv[])
{
   if (argc < 5)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }
   printf("\n");
   for (int i = 3; i < argc; i++)
   {
      printf("%s ", argv[i]);
   }
   printf("\n");


   const int n = (argc - 1 - 2);
   char arr[n];
   memset(arr, 0, n);
   for (int i = 0; i < n; i++)
   {
      arr[i] = argv[i+3][0];
      printf("%c ", arr[i]);
   }
   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   engine(x,y,n,arr);
}
/*
Running: ./a.out  6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1
Comparing result to: /y/shared/Engineering/cs-drbc/assignments/w20 6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1
Expected
0 1 0 1 0 0
1 0 1 0 1 0
0 1 0 0 0 1
1 0 0 0 1 0
0 1 0 1 0 1
0 0 1 0 1 0
Graph is Bipartite

Got

0 1 0 0 1 0 1 0 0 0 1 1 0 1
0 1 0 0 1 0 1 0 0 0 1 1 0 1
If there is a lot of output, you could narrow down the error by doing a diff:
diff -y <(./a.out  6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1) <(/y/shared/Engineering/cs-drbc/assignments/w20 6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1)
   or
diff  <(./a.out  6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1) <(/y/shared/Engineering/cs-drbc/assignments/w20 6  1 0 1 0 0   1 0 1 0   0 0 1   1 0   1 2>&1)
*/


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