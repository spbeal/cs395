#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD 100
#define INF 1000000000

// Global variables
int V, U;
int G[MAX_BOARD][MAX_BOARD];   // Adjacency matrix: V x U

// Matching arrays: for each vertex in V and U store its partner (-1 if unmatched)
int matchV[MAX_BOARD]; 
int matchU[MAX_BOARD];

// For BFS: distance for V vertices
int dist[MAX_BOARD];
// Queue for BFS
int queue[MAX_BOARD];
int front, rear;

void printM();
void printQueue();
// BFS to compute shortest distances from free vertices in V to all V vertices
// (while also "relaxing" through adjacent U vertices)
int bfs() {
   
    front = rear = 0;
    // Initialize distances for V vertices
    for (int v = 0; v < V; v++) {
        if (matchV[v] == -1) {
            dist[v] = 0;
            queue[rear++] = v;
        } else {
            dist[v] = INF;
        }
    }
    
    int distance = INF;
    // Process queue
    while (front < rear) {
        int v = queue[front++];
        if (dist[v] < distance) {
            for (int u = 0; u < U; u++) {
                if (G[v][u]) { // There is an edge from v to u
                    // If u is free then we found an augmenting path (record its distance)
                    if (matchU[u] == -1) {
                        if (dist[v] + 1 < distance)
                            distance = dist[v] + 1;
                    } 
                    // Otherwise, relax the edge and add the matched V vertex to the queue
                    else if (dist[matchU[u]] == INF) {
                        dist[matchU[u]] = dist[v] + 1;
                        queue[rear++] = matchU[u];
                    }
                }
            }
        }
    }
    return distance != INF;
}

// DFS to find an augmenting path starting from vertex v
int dfs(int v, int distance) {
    if (dist[v] == distance) {
        dist[v] = INF;  // Prevent revisiting v in this phase
        for (int u = 0; u < U; u++) {
            if (G[v][u]) {
                int w = matchU[u];
                // If u is free or if we can find an augmenting path from the vertex matched with u
                if (w == -1 || (dist[w] == distance + 1 && dfs(w, distance + 1))) {
                    matchV[v] = u;
                    matchU[u] = v;
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Hopcroft-Karp algorithm for maximum bipartite matching
int hopcroftKarp() {
    int matching = 0;
    // Initialize all vertices as free
    for (int v = 0; v < V; v++) {
        matchV[v] = -1;
    }
    for (int u = 0; u < U; u++) {
        matchU[u] = -1;
    }
    
    // While there is an augmenting path, try to use DFS from every free vertex in V
    while (bfs()) {
        for (int v = 0; v < V; v++) {
            if (matchV[v] == -1 && dfs(v, 0))
                matching++;
        }
    }
    return matching;
}

void printQueue() {
   printf("Queue:");
   for (int i = front; i < rear; i++) {
       printf(" %d", queue[i]);
   }
   printf("\n");
}


// Utility function to print the matching pairs
void printMatching() {
    printf("Matching pairs (V -> U):\n");
    for (int v = 0; v < V; v++) {
        if (matchV[v] != -1)
            // Convert U back to original numbering if needed (e.g., add 5) here
            printf("V%d -> U%d\n", v, matchV[v]+5);
        else
            printf("V%d is free\n", v);
    }
}


void printM() {
   printf("\t");
   for (int v = 0; v < V; v++) {
      if (matchV[v] != -1) {
          printf("V%d ", v);
      }
  }
  printf("\n");
  printf("\t");
  for (int v = 0; v < V; v++) {
      if (matchV[v] != -1) {
         printf("|  ");
      }
   }
   printf("\n");
   printf("\t");
   for (int v = 0; v < V; v++) {
      if (matchV[v] != -1) {
          printf("U%d ", matchV[v]+5);
      }
   }
   printf("\n");

}

void printGraph() {
    for (int v = 0; v < V; v++) {
       printf("%d ->", v);
       for (int u = 0; u < U; u++) {
           if (G[v][u]) {
               // If you need to convert u to original numbering, add an offset here (e.g., +5)
               printf(" %d", u+5);
           }
       }
       printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s V U [adjacency lists]\n", argv[0]);
        return 1;
    }
    
    V = atoi(argv[1]);
    U = atoi(argv[2]);
    memset(G, 0, sizeof(G));
    
    // Parse adjacency lists.
    // For each V vertex, read numbers until an "X" is encountered.
    // It is assumed that U vertices in the input are given with an offset (e.g., starting at 5).
    int arg_idx = 3;
    for (int v = 0; v < V; v++) {
        while (arg_idx < argc && strcmp(argv[arg_idx], "X") != 0) {
            int u = atoi(argv[arg_idx++]) - 5; // Convert input to 0-based index
            if (u >= 0 && u < U)
                G[v][u] = 1;
        }
        arg_idx++; // Skip the "X"
    }
    
    printGraph();
    int matching = hopcroftKarp();
   //  printf("Maximum matching size: %d\n", matching);
   //  printMatching();
    
    return 0;
}
