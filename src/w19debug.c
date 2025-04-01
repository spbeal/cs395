#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD 100

// Global variables
int V, U, start, end;
int G[MAX_BOARD][MAX_BOARD];        // Adjacency matrix (V x U)
int M[MAX_BOARD][2];                // Matching pairs [V][U]
int labelV[MAX_BOARD], labelU[MAX_BOARD];
int queue[MAX_BOARD * 2];           // Queue for BFS traversal

void enqueue(int x) {
    queue[end++] = x;
    printf("[ENQUEUE] Added %d to queue. (start=%d, end=%d)\n", x, start, end);
}

int dequeue() {
    int x = queue[start++];
    printf("[DEQUEUE] Removed %d from queue. (start=%d, end=%d)\n", x, start, end);
    return x;
}

void printQueue() {
    printf("[QUEUE] Current state:");
    for (int i = start; i < end; i++) {
        printf(" %d", queue[i]);
    }
    printf("\n");
}

void printGraph() {
    printf("\n[GRAPH] Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        printf("V%d ->", i);
        for (int j = 0; j < U; j++) {
            if (G[i][j]) {
                printf(" U%d", j + 5);
            }
        }
        printf("\n");
    }
}

void printMatching() {
    printf("\n[MATCHING]\n");
    for (int i = 0; i < V; i++) {
        if (M[i][0] != -1) {
            printf("V%d -> U%d\n", i, M[i][0] + 5);
        }
    }
    printf("\n");
}

void printLabels() {
    printf("[LABELS]\nlabelV: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", labelV[i]);
    }
    printf("\nlabelU: ");
    for (int i = 0; i < U; i++) {
        printf("%d ", labelU[i]);
    }
    printf("\n");
}

void MaximumBipartiteMatching() {
    memset(M, -1, sizeof(M));
    int updated;

    do {
        start = end = 0;
        memset(labelV, -1, sizeof(labelV));
        memset(labelU, -1, sizeof(labelU));
        updated = 0;

        printf("\n--- [NEW BFS ITERATION] ---\n");
        
        // Initialize queue with free V vertices
        for (int v = 0; v < V; v++) {
            if (M[v][0] == -1) {
                enqueue(v);
                labelV[v] = -2;
            }
        }
        printQueue();
        printLabels();

        while (start < end) {
            printMatching();

            int w = dequeue();

            if (w < V) { // Processing V vertex
                printf("[PROCESS] V%d\n", w);
                for (int u = 0; u < U; u++) {
                  printLabels();
                    if (G[w][u] && labelU[u] == -1) {
                        labelU[u] = w;
                        printf("[MATCH ATTEMPT] V%d -> U%d\n", w, u + 5);

                        if (M[u][0] == -1) { // If U is free
                            printf("[AUGMENTING PATH FOUND] Matching V%d -> U%d\n", w, u + 5);
                            int v = w;
                            while (v != -2) {
                                int prev_u = labelU[v];
                                if (M[v][0] != -1) {
                                    M[v][1] = -1;
                                }
                                M[v][0] = u;
                                M[u][1] = v;
                                v = (prev_u != -1) ? labelV[prev_u] : -2;
                            }

                            // Reset and restart search
                            memset(labelV, -1, sizeof(labelV));
                            memset(labelU, -1, sizeof(labelU));
                            start = end = 0;
                            updated = 1;
                            printf("[RESET] Augmenting path applied, restarting BFS.\n");
                            break;
                        } else { // U is already matched
                            if (M[u][1] != -1) {
                                printf("[ENQUEUE] Adding matched V%d (from U%d) to queue.\n", M[u][1], u + 5);
                                labelV[M[u][1]] = u;
                                enqueue(M[u][1] + V);
                            }
                        }
                    }
                }
            } else { // Processing U vertex
                int u = w - V ;
                printf("[PROCESS] U%d\n", u + 5);
                if (M[u][1] != -1) {
                    printf("[ENQUEUE] Adding V%d from U%d match to queue.\n", M[u][1], u + 5);
                    labelV[M[u][1]] = u;
                    enqueue(M[u][1]);
                }
            }
        }
    } while (updated);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s V U [adjacency lists]\n", argv[0]);
        return 1;
    }

    V = atoi(argv[1]);
    U = atoi(argv[2]);
    memset(G, 0, sizeof(G));

    // Parse adjacency lists
    int arg_idx = 3;
    for (int v = 0; v < V; v++) {
        while (arg_idx < argc && strcmp(argv[arg_idx], "X") != 0) {
            int u = atoi(argv[arg_idx++]) - 5; // Convert to 0-based
            if (u < U) G[v][u] = 1;
        }
        if (arg_idx < argc) arg_idx++; // Skip "X"
    }

    printGraph();
    MaximumBipartiteMatching();
    return 0;
}
