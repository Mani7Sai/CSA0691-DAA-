#include <stdio.h>
#include <limits.h>
#define MAXCITIES 20
int n;
int dist[MAXCITIES][MAXCITIES]; 
int memo[MAXCITIES][1 << MAXCITIES]; 
int VISITED_ALL; 
int tsp(int current, int mask) {
    if (mask == VISITED_ALL) { 
        return dist[current][0]; 
    }
    if (memo[current][mask] != -1) {
        return memo[current][mask];
    }
    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newCost = dist[current][city] + tsp(city, mask | (1 << city));
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }
    memo[current][mask] = minCost;
    return minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }
    VISITED_ALL = (1 << n) - 1;
    int minCost = tsp(0, 1);
    printf("Minimum cost for TSP: %d\n", minCost);
    return 0;
}
