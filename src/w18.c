/*********************************************
 * Id: beal6782
 * 
 * The Clique Problem 
 * 
 * Exhaustive search algorithm for determining number of vertices in clique
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
The Clique Problem 

A clique, C, in an undirected graph G = (V, E) is a subset of the vertices, 
such that every two distinct vertices in C are adjacent. 
In other words, a clique is a complete subgraph of G. 
The size of a clique is the number of vertices it contains. 
The clique problem is the optimization problem of finding a clique of maximum size in a graph.

Design an exhaustive-search algorithm for determining the number of verticies in the largest cliquse in the graph.

The input to your program will be command line arguements in the form 
   number_of_elements upper triangle of adjacency matrix.
For examle 
   ./clique 6  1 0 0 1 1  1 1 0 0  1 1 1  0 1  1
Represents the graph
  1 0 0 1 1
    1 1 0 0
      1 1 1
        0 1
          1

Your output should be like this:
./clique 7 1 1 0 1 1 0   1 1 0 1 0     1 0 0 1     1 1 1     0 1      0
0 1 1 0 1 1 0
1 0 1 1 0 1 0
1 1 0 1 0 0 1
0 1 1 0 1 1 1
1 0 0 1 0 0 1
1 1 0 1 0 0 0
0 0 1 1 1 0 0
No clique found of size 7
No clique found of size 6
No clique found of size 5
No clique found of size 4
Clique found of size 3
*/