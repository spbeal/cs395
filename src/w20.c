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
   if (argc < 3)
   {
      printf("%s ./clique 6  1 0 0 1 1  1 1 0 0  1 1 1  0 1  1", argv[0]);
      exit(1);
   }

   const int n = atoi(argv[1]);
   int arr[n][n];

   int k = 2; 
   int j = 0;
   for (int j = 0; j < n; j++)
   {
      for (int space = 0; space < j+1; space++) { printf(" "); printf(" "); } 
      for (int i = 1+j; (i < n && k < argc); i++)
      {
         arr[i][j] = atoi(argv[k++]);
         // if (argv[k][0] == ' ' && argv[k+1] == ' ') j++;
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
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