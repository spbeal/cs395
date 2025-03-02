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
The Clique Problem 

A clique, C, in an undirected graph G = (V, E) is a subset of the vertices, 
such that every two distinct vertices in C are adjacent. 
In other words, a clique is a complete subgraph of G. 
The size of a clique is the number of vertices it contains. 
The clique problem is the optimization problem of finding a clique of maximum size in a graph.

Design an exhaustive-search algorithm for determining the number of verticies in the largest clique in the graph.

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