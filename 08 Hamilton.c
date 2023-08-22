#include <stdio.h>
#include <stdbool.h>
#define V 5 
int path[V];      
bool visited[V]; 
void printHamiltonianCircuit() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); 
}
bool isSafe(int v, int pos, int graph[V][V]) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}
bool hamiltonianCircuitUtil(int graph[V][V], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printHamiltonianCircuit();
            return true;
        }
        return false;
    }

    for (int v = 1; v < V; v++) {
        if (!visited[v] && isSafe(v, pos, graph)) {
            path[pos] = v;
            visited[v] = true;

            if (hamiltonianCircuitUtil(graph, pos + 1))
                return true;

            path[pos] = -1; 
            visited[v] = false;
        }
    }

    return false;
}

bool findHamiltonianCircuit(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        path[i] = -1;
        visited[i] = false;
    }

    path[0] = 0; 
    visited[0] = true; 

    if (hamiltonianCircuitUtil(graph, 1) == false) {
        printf("No Hamiltonian Circuit exists\n");
        return false;
    }

    return true;
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix (%d x %d) for the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (findHamiltonianCircuit(graph) == false)
        printf("No Hamiltonian Circuit exists\n");

    return 0;
}
