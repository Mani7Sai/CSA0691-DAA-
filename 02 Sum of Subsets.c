#include <stdio.h>
#define MAX_SIZE 100
int set[MAX_SIZE];
int solution[MAX_SIZE];
int n, targetSum;
void subsetSum(int index, int currentSum, int size) {
    if (currentSum == targetSum) {
        printf("Subset: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }
    if (currentSum > targetSum || index >= n) {
        return; 
    }
    solution[size] = set[index];
    subsetSum(index + 1, currentSum + set[index], size + 1);
    subsetSum(index + 1, currentSum, size);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets with the sum %d:\n", targetSum);
    subsetSum(0, 0, 0);
    return 0;
}
