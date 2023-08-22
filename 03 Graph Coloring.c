#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices, numColors;
bool isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoring(int v) {
    if (v == numVertices) {
        return true;
    }
    for (int c = 1; c <= numColors; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;
            if (graphColoring(v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    if (graphColoring(0)) {
        printf("Graph can be colored using %d colors as follows:\n", numColors);
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", numColors);
    }

    return 0;
}
