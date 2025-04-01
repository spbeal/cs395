#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD 100

// Global variables for graph and matching.
int V, U;
int G[MAX_BOARD][MAX_BOARD];   // Adjacency matrix for V x U

// Matching arrays: matchV[v] is the U vertex matched to v; matchU[u] is the V vertex matched to u.
// -1 indicates that the vertex is free.
int matchV[MAX_BOARD];
int matchU[MAX_BOARD];

// Label arrays for the search (used to reconstruct augmenting paths).
// For V vertices: labelV[v] stores the U vertex from which v was reached, or -2 if v is free.
// For U vertices: labelU[u] stores the V vertex from which u was reached.
int labelV[MAX_BOARD], labelU[MAX_BOARD];

// Encoded queue: values less than V represent V–vertices; values ≥ V represent U–vertices (decoded by subtracting V).
int queue[MAX_BOARD * 2];
int start, end;

// Forward declaration.
void printQueue();

// Enqueue a value and then print the queue.
void enqueue(int x) {
    queue[end++] = x;
   //  printQueue();
}

// Dequeue a value.
int dequeue() {
    return queue[start++];
}

// Print the queue contents (raw encoded values).
void printQueue() {
    printf("Queue:");
    for (int i = start; i < end; i++) {
        printf(" %d", queue[i]);
    }
    printf("\n");
}

// Print the graph: for each V vertex, list its adjacent U vertices (converted back by adding 5).
void printGraph() {
    for (int i = 0; i < V; i++) {
        printf("%d ->", i);
        for (int j = 0; j < U; j++) {
            if (G[i][j])
                printf(" %d", j + 5);
        }
        printf("\n");
    }
}

// Print the current matching as three rows.
// First row: the V vertices (e.g., "V0") that are matched.
// Second row: a column of pipes.
// Third row: the corresponding U vertices (converted back by adding 5).
void printMatching() {
    int printed = 0;
    for (int v = 0; v < V; v++) {
        if (matchV[v] != -1) {
            printf("\tV%d", v);
            printed = 1;
        }
    }
    if(printed) printf("\n");
    
    printed = 0;
    for (int v = 0; v < V; v++) {
        if (matchV[v] != -1) {
            printf("\t| ");
            printed = 1;
        }
    }
    if(printed) printf("\n");
    
    printed = 0;
    for (int v = 0; v < V; v++) {
        if (matchV[v] != -1) {
            printf("\tU%d", matchV[v] + 5);
            printed = 1;
        }
    }
    if(printed) printf("\n");
}

// The main algorithm that finds an augmenting path step‐by–step while printing the queue and matching.
void MaximumBipartiteMatching() {
    // Initialize all matchings to -1 (free).
    for (int v = 0; v < V; v++)
        matchV[v] = -1;
    for (int u = 0; u < U; u++)
        matchU[u] = -1;
    
    int updated;
    do {
        updated = 0;
        start = end = 0;
        memset(labelV, -1, sizeof(labelV));
        memset(labelU, -1, sizeof(labelU));
        
        // Enqueue all free V vertices and mark them with -2.
        for (int v = 0; v < V; v++) {
            if (matchV[v] == -1) {
                enqueue(v);
                labelV[v] = -2;  // marker for free vertex
            }
        }
        
        // Process the queue until it is empty.
        while (start < end) {
         printQueue();
            int w = dequeue();
            // If w represents a V vertex.
            if (w < V) {
                for (int u = 0; u < U; u++) {
                    if (G[w][u] && labelU[u] == -1) {
                        // Record that u was reached from V vertex w.
                        labelU[u] = w;
                        // Instead of immediate augmentation when u is free, enqueue u (encoded) first.
                        if (matchU[u] == -1) {
                            enqueue(u + V);
                        } else {
                            // u is matched; enqueue the V vertex it is matched to (encoded as U vertex) if not already labeled.
                            int vPrime = matchU[u];
                            if (labelV[vPrime] == -1) {
                                labelV[vPrime] = u;
                                enqueue(vPrime + V);
                            }
                        }
                    }
                }
            } else {
                // w encodes a U vertex.
                int u = w - V;
                // If u is free, then we have reached an augmenting endpoint.
                if (matchU[u] == -1) {
                    // Backtrack using labelU to update the matching.
                    int curU = u;
                    int curV = labelU[u];  // must have been set when enqueuing u from some V vertex.
                    while (curV != -2) {
                        int temp = matchV[curV];  // previous match for curV (could be -1)
                        matchV[curV] = curU;
                        matchU[curU] = curV;
                        curU = temp;
                        if(curU == -1)
                            curV = -2;
                        else
                            curV = labelU[curU];
                    }
                    updated = 1;
                    // Clear the queue to force a new BFS round.
                    start = end = 0;
                    break;  // break out of while loop.
                } else {
                    // Otherwise, u is not free. Let v be the vertex matched with u.
                    int v = matchU[u];
                    if (v != -1 && labelV[v] == -1) {
                        labelV[v] = u;  // record that v was reached via u.
                        enqueue(v);
                    }
                }
            }
            // Print the current matching after each dequeue.
            printMatching();
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
    
    // Parse the adjacency lists.
    // Each V vertex’s list ends with "X". The input U numbers are assumed to be given with an offset (starting at 5).
    int arg_idx = 3;
    for (int v = 0; v < V; v++) {
        while(arg_idx < argc && strcmp(argv[arg_idx], "X") != 0) {
            int u = atoi(argv[arg_idx++]) - 5; // Convert to 0-based index.
            if(u >= 0 && u < U)
                G[v][u] = 1;
        }
        arg_idx++; // Skip the "X"
    }
    
    printGraph();
    MaximumBipartiteMatching();
    return 0;
}
