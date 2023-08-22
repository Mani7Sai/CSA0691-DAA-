#include <stdio.h>
#include <limits.h>
#define N 5
int costMatrix[N][N];
int assignment[N];
int usedRows[N], usedCols[N];
int minCost = INT_MAX;

void printAssignment() {
    printf("Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d is assigned to Task %d (Cost %d)\n", i + 1, assignment[i] + 1, costMatrix[i][assignment[i]]);
    }
}

void branchAndBound(int agent, int costSoFar) {
    if (agent == N) {
        if (costSoFar < minCost) {
            minCost = costSoFar;
            printAssignment();
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (!usedCols[task] && (costSoFar + costMatrix[agent][task] < minCost)) {
            assignment[agent] = task;
            usedCols[task] = 1;
            branchAndBound(agent + 1, costSoFar + costMatrix[agent][task]);
            usedCols[task] = 0;
        }
    }
}

int main() {
    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }

    branchAndBound(0, 0);

    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
