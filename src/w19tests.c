#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD 100

// Global variables matching your definitions
int V, U, start, end;
int G[MAX_BOARD][MAX_BOARD];        // Adjacency matrix (V x U)
int M[MAX_BOARD][2];                // Matching pairs [V][U]
int labelV[MAX_BOARD], labelU[MAX_BOARD];
int queue[MAX_BOARD * 2];           // Queue for BFS traversal

void enqueue(int x) {
   queue[end++] = x;
}

int dequeue() {
   int x = queue[start];
   start++;
   return x;
}

void printQueue() {
   printf("Queue:");
   for (int i = start; i < end; i++) {
       printf(" %d", queue[i]);
   }
   printf("\n");
}

void printGraph() {
   for (int i = 0; i < V; i++) {
       printf("%d ->", i);
       for (int j = 0; j < U; j++) {
           if (G[i][j]) {
               printf(" %d", j + 5); // Convert back to original U numbers
           }
       }
       printf("\n");
   }
}

void printM() {
   printf("\t");
   for (int i = 0; i < V; i++) {
       if (M[i][0] != -1) {
           printf("V%d ", i);
       }
   }
   printf("\n\t");
   for (int i = 0; i < V; i++) {
       if (M[i][0] != -1) {
           printf("|  ");
       }
   }
   printf("\n\t");
   for (int i = 0; i < V; i++) {
       if (M[i][0] != -1) {
           printf("U%d ", M[i][1] + 5); // Convert back to original U numbers
       }
   }
   printf("\n");
}

// void printM(int start, int end) {
//    int i;
//    for(i=0; i<end; i++)
//    {
//       if (M[i][0] != -1) {
//       printf("\tV%d", i);
//       }
//    }
//    printf("\n");

//    for(i=0; i<end; i++)
//    {
//       if (M[i][0] != -1) {
//       printf("\t|");
//       }
//    }
//    printf("\n");

//    for(i=0; i<end; i++)
//    {
//       if (M[i][0] != -1) {
//       printf("\tU%d", M[i][1]+5);
//       }
//    }
//    printf("\n");
// }


void MaximumBipartiteMatching() {
   memset(M, -1, sizeof(M));
   int updated;

   do {
      start = end = 0;
      memset(labelV, -1, sizeof(labelV));
      memset(labelU, -1, sizeof(labelU));
      updated = 0;

       // Initialize queue with free V vertices
       for (int v = 0; v < V; v++) {
           if (M[v][0] == -1) {
               enqueue(v);
               //queue[end++] = v;
               labelV[v] = -2; // Mark as free V
           }
       }

       while (start < end) {
           printQueue();
           int w = dequeue();

           if (w < V) { // Process V vertex // if labelV[w]
               for (int u = 0; u < U; u++) {
                   if (G[w][u] && labelU[u] == -1) {
                       labelU[u] = w;
                       if (M[u][0] == -1) { // U is free
                           // Augment the path
                           int v = w;
                           while (v != -2) {
                              int prev_u = labelU[v];
                               if (M[v][0] != -1) {
                                   M[M[v][0]][1] = -1; // Remove old match
                                   // M[v][1] = -1;
                               }
                              M[v][0] = u;
                              M[u][1] = v;
                              // v = labelV[prev_u];
                              v = (prev_u != -1) ? labelV[prev_u] : -2;
                           }
                           // Reset and reinitialize
                           memset(labelV, -1, sizeof(labelV));
                           memset(labelU, -1, sizeof(labelU));
                           // printM(start,end);
                           start = end = 0;
                           updated = 1;
                           // printM();
                           break;

                       } else { // U is matched
                           //if (M[u][1] != -1) {
                              labelV[M[u][1]] = u;
                              queue[end++] = M[u][1] + V; // Enqueue as U vertex
                           //}
                       }
                   }
               }
               // end of for loop
           } else { // Process U vertex (encoded as V + u)
               int u = w - V;
               labelV[M[u][1]] = u;
               queue[end++] = M[u][1]; // Enqueue V vertex
           }
         // printM(start, end);
         printM();
       }
   } while (updated);
}

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Usage: %s V U [adjacency lists]\n", argv[0]);
        return 1;
    }

    V = atoi(argv[1]);
    U = atoi(argv[2]);
    memset(G, 0, sizeof(G));

   //  // Parse adjacency lists
    int arg_idx = 3;
    for(int v=0; v<V; v++) {
        while(arg_idx < argc && strcmp(argv[arg_idx], "X") != 0) {
            int u = atoi(argv[arg_idx++]) - 5; // Convert to 0-based
            if(u < U) G[v][u] = 1;
        }
        if(arg_idx < argc) arg_idx++; // Skip "X"
    }

    printGraph();
    MaximumBipartiteMatching();
    return 0;
}