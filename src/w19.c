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

#define MAX_BOARD 100

int V, U, start, end;
int G[MAX_BOARD][MAX_BOARD];
//int matchV[MAX_BOARD], matchU[MAX_BOARD];
int M[MAX_BOARD][2];
int labelV[MAX_BOARD], labelU[MAX_BOARD];
int queue[MAX_BOARD * 2];

/////////////////////////////////////////////////
/////////////////////////////////////////////////

// Print out the currenlty found matchings
void printM(int start, int end) {
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
// void printM() {
//    printf("\t");
//    for (int u = 0; u < U; u++) {
//        if (matchU[u] != -1) {
//            printf("V%d ", matchU[u]);
//        }
//    }
//    printf("\n\t");
//    for (int u = 0; u < U; u++) {
//        if (matchU[u] != -1) {
//            printf("|  ");
//        }
//    }
//    printf("\n\t");
//    for (int u = 0; u < U; u++) {
//        if (matchU[u] != -1) {
//            printf("U%d ", u);
//        }
//    }
//    printf("\n");
// }

/////////////////////////////////////////////////
/////////////////////////////////////////////////

/*
 * Queue Functions
*/

void printQueue() {
   printf("Queue:");
   for (int i = start; i < end; i++) {
       printf(" %d", queue[i]);
   }
   printf("\n");
}

void enqueue(int x) {
   queue[end++] = x;
}

int dequeue() {
   return queue[start++];
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

void MaximumBipartiteMatching() {
   memset(matchV, -1, sizeof(matchV));
   memset(matchU, -1, sizeof(matchU));
   int updated;

   do {
      start = end = 0;
       memset(labelV, -1, sizeof(labelV));
       memset(labelU, -1, sizeof(labelU));
       updated = 0;

       for (int v = 0; v < V; v++) {
           if (matchV[v] == -1) {
               enqueue(v);
               labelV[v] = -2;
           }
       }

       if (start == end) break;

       while (start < end) {
           printQueue();
           int w = dequeue();

           if (w < V) {
               for (int u = 0; u < U; u++) {
                   if (G[w][u]&& labelU[u] == -1) {
                       labelU[u] = w;
                       if (matchU[u] == -1) {
                           int v = w;
                           while (v != -2) {
                               int prev_u = labelU[matchV[v]];
                               matchU[matchV[v]] = -1;
                               matchV[v] = u;
                               matchU[u] = v;
                               v = labelV[v];
                               if (v != -2) {
                                   u = prev_u;
                               }
                           }
                           memset(labelV, -1, sizeof(labelV));
                           memset(labelU, -1, sizeof(labelU));
                           start = end = 0;
                           updated = 1;
                           printM();
                           break;
                       } else {
                           labelV[matchU[u]] = w;
                           enqueue(matchU[u]);
                       }
                   }
               }
               if (updated) break;
           }
       }
   } while (updated);
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

void printGraph() {
   for (int i = 0; i < V; i++) {
       printf("%d ->", i);
       for (int j = 0; j < U; j++) {
           if (G[i][j]) {
               printf(" %d", G[i][j]); // j
           }
       }
       printf("\n");
   }
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

int main (int argc, char *argv[])
{
   if (argc < 5) {
      printf("%s V U [adjacency lists separated by X]\n", argv[0]);
      return 1;
  }
   
   V = atoi(argv[1]);
   U = atoi(argv[2]);
   memset(G, 0, sizeof(G));

   int k = 3; 
   for (int i = 0; i < V; i++)
   {
      for (int j = 0; (j < U && k < argc); j++)
      {
         if (argv[k][0] == 'X') 
         {
            k++;
            break;
         }
         G[i][j] = atoi(argv[k++]);
      }
   }

   printGraph();
   MaximumBipartiteMatching();
   return 0;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

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
         for every vertex U adjacent to w do
            if U is free
               //augment
               M ←M ∪ (w, U)
               v←w
               while V is labeled do
                  u←vertex indicated by v’s label; M ←M − (V, U)
                  v←vertex indicated by u’s label; M ←M ∪ (V, U)
               remove all vertex labels
               reinitialize Q with all free vertices in V
               break //exit the for loop
            else //U is matched
               if (w, U) is not an element of M and U is unlabeled
                  label U with w
                  Enqueue(Q, U)
      else //w is and element of U (and matched)
         label the mate V of w with w
         Enqueue(Q, V)
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