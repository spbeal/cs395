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
#include <stdbool.h>

#define MAX_N 50
int n;
int graph[MAX_N][MAX_N];

// Function to check if a set of vertices forms a clique
bool is_clique(int subset, int size) {
   int vertices[size], index = 0;
   for (int i = 0; i < n; i++) {
       if (subset & (1 << i)) {
           vertices[index++] = i;
       }
   }
   
   for (int i = 0; i < size; i++) {
       for (int j = i + 1; j < size; j++) {
           if (!graph[vertices[i]][vertices[j]]) {
               return false;
           }
       }
   }
   return true;
}

// Function to find the largest clique using exhaustive search
int find_clique() {
   int max_clique_size = 0;
   int total_subsets = (1 << n);
   
   for (int subset = 1; subset < total_subsets; subset++) {
       int size = __builtin_popcount(subset);
       if (size > max_clique_size && is_clique(subset, size)) {
           max_clique_size = size;
       }
   }
   return max_clique_size;
}

void find_largest_clique()
{
   for (int size = n; size >= 1; size--) {
      if (find_clique() >= size) {
          printf("Clique found of size %d\n", size);
          return;
      } else {
          printf("No clique found of size %d\n", size);
      }
  }
}

void build_adjacency_matrix(int *values) {
   int index = 0;
   for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) {
         graph[i][j] = graph[j][i] = values[index++];
       }
   }
}

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s ./clique 6  1 0 0 1 1  1 1 0 0  1 1 1  0 1  1", argv[0]);
      exit(1);
   }
   // int k = 2; 
   // for (int i = 0; i < n; i++)
   // {
   //    for (int space = 0; space < j+1; space++) { printf(" "); printf(" "); } 
   //    for (int j = 1+i; (j < n && k < argc); j++)
   //    {
   //       arr[i][j] = atoi(argv[k++]);
   //       printf("%d ", arr[i][j]);
   //    }
   //    printf("\n");
   // }

   n = atoi(argv[1]);
   int values[(n * (n - 1)) / 2];
   for (int i = 0; i < argc-1; i++) {
       values[i] = atoi(argv[i+2]);
   }

   build_adjacency_matrix(values);
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j<n; j++)
         printf("%d ", graph[i][j]);
      printf("\n");
   }

   find_largest_clique();
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

/*
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

Running: ./a.out  15 0 0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1
Comparing result to: /y/shared/Engineering/cs-drbc/assignments/w18 15 0 0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1
Expected 
0 0 0 0 1 1 0 1 1 1 1 0 1 1 0
0 0 1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 0 1 0 1 1 0 0 0 1 1 1 1 0
0 1 1 0 1 0 0 1 1 1 0 1 1 0 1
1 1 0 1 0 1 0 1 1 1 1 1 1 0 1
1 1 1 0 1 0 0 0 1 0 0 1 0 1 1
0 1 1 0 0 0 0 1 1 1 1 1 1 1 1
1 1 0 1 1 0 1 0 1 1 1 0 1 1 0
1 1 0 1 1 1 1 1 0 0 1 1 0 1 1
1 1 0 1 1 0 1 1 0 0 1 1 1 1 0
1 1 1 0 1 0 1 1 1 1 0 1 1 0 1
0 1 1 1 1 1 1 0 1 1 1 0 1 1 1
1 1 1 1 1 0 1 1 0 1 1 1 0 1 1
1 0 1 0 0 1 1 1 1 1 0 1 1 0 0
0 0 0 1 1 1 1 0 1 0 1 1 1 0 0
No clique found of size 15
No clique found of size 14
No clique found of size 13
No clique found of size 12
No clique found of size 11
No clique found of size 10
No clique found of size 9
No clique found of size 8
No clique found of size 7
Clique found of size 6

Got

0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0
0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0
If there is a lot of output, you could narrow down the error by doing a diff:
diff -y <(./a.out  15 0 0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1) <(/y/shared/Engineering/cs-drbc/assignments/w18 15 0 0 0 1 1 0 1 1 1 1 0 1 1 
0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1)
   or
diff  <(./a.out  15 0 0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1) <(/y/shared/Engineering/cs-drbc/assignments/w18 15 0 0 0 1 1 0 1 1 1 1 0 1 1 0 
1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 2>&1)
*/