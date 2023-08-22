#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int weights[MAX_ITEMS];
int values[MAX_ITEMS];
int numItems;
int maxWeight;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int item, int weight) {
    if (item == numItems || weight == 0) {
        return 0;
    }

    if (weights[item] > weight) {
        return knapsack(item + 1, weight);
    } else {
        int include = values[item] + knapsack(item + 1, weight - weights[item]);
        int exclude = knapsack(item + 1, weight);
        return max(include, exclude);
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    int optimalValue = knapsack(0, maxWeight);

    printf("The optimal value is: %d\n", optimalValue);

    return 0;
}
