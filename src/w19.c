/*********************************************
 * Id: beal6782
 * 
 * MaximumBipartiteMatching BFS-based 
 * 
 * Implement an algorithm for finding a bipartite graph
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
Note: The input is an adjacenty list delimited by X
      argv[1] is the number of V verticies.
      argv[2] is the number of U verticies.
      after that each value is an adjacent U for the current V.
./w19 5 4 5 6 X 6 7 X 7 8 X 5  X 5
0 -> 5 6
1 -> 6 7
2 -> 7 8
3 -> 5
4 -> 5
*/

/*
MaximumBipartiteMatching BFS-based 

Read section 10.3 of the text book.
DESCRIPTION: A graph is said to be bipartite if all its vertices can be 
partitioned into two disjoint subsets X and Y so that every edge connects 
a vertex in X with a vertex in Y. 

Before calling MaximumBipartiteMatching(G) 
   printGraph(G)

//Finds a maximum matching in a bipartite graph by a BFS-like traversal
//Input: A bipartite graph G = Adjacenty Matrix
//Output: A maximum-cardinality matching M (array of (V,U) edges in the input graph
MaximumBipartiteMatching(G)
   initialize set M of edges with some valid matching (e.g., the empty set)
   initialize queue Q with all the free vertices in V (in any order)
   while not Empty(Q) do
      printQueue(Q)
      w←Front(Q); Dequeue(Q)
      if w is an element of V
         for every vertex u adjacent to w do
            if u is free
               //augment
               M ←M ∪ (w, u)
               v←w
               while v is labeled do
                  u←vertex indicated by v’s label; M ←M − (v, u)
                  v←vertex indicated by u’s label; M ←M ∪ (v, u)
               remove all vertex labels
               reinitialize Q with all free vertices in V
               break //exit the for loop
            else //u is matched
               if (w, u) is not an element of M and u is unlabeled
                  label u with w
                  Enqueue(Q, u)
      else //w is and element of U (and matched)
         label the mate v of w with w
         Enqueue(Q, v)
      printM(M)
   return M //current matching is maximum

Note: These are my print functions. Your may vary if you have different data structures.
// Print the adjacentcy matrix.
void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies) {
   int i, j;
   for(i=0; i<Vverticies; i++)
   {
      printf("%d ->", i);
      j=0;
      while(G[i][j] != BCEMPTY)
      {
         printf(" %d", G[i][j]);
         j++;
      }
      printf("\n");
   }
}

// Print out the current contents of the queue for debugging
void printQueue(int Queue[], int start, int end) {
   int i;
   printf("Queue:");
   for(i=start; i<end; i++)
   {
      printf(" %d", Queue[i]);
   }
   printf("\n");
}

// Print out the currenlty found matchings
void printM(int M[][2], int start, int end) {
   int i;
   for(i=start; i<end; i++)
   {
      printf("\tV%d", M[i][0]);
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\t|");
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\tU%d", M[i][1]);
   }
   printf("\n");
}

Note: The input is an adjacenty list delimited by X
      argv[1] is the number of V verticies.
      argv[2] is the number of U verticies.
      after that each value is an adjacent U for the current V.
./w19 5 4 5 6 X 6 7 X 7 8 X 5  X 5
0 -> 5 6
1 -> 6 7
2 -> 7 8
3 -> 5
4 -> 5
Queue: 0 1 2 3 4
        V0
        |
        U5
Queue: 1 2 3 4
        V0      V1
        |       |
        U5      U6
Queue: 2 3 4
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 3 4
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 4 5
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 5
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 0
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 6
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 1
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 7
        V0      V1      V2
        |       |       |
        U5      U6      U7
Queue: 2
        V2      V1      V0      V3
        |       |       |       |
        U8      U7      U6      U5
Queue: 4
        V2      V1      V0      V3
        |       |       |       |
        U8      U7      U6      U5
Queue: 5
        V2      V1      V0      V3
        |       |       |       |
        U8      U7      U6      U5
Queue: 3
        V2      V1      V0      V3
        |       |       |       |
        U8      U7      U6      U5

*/