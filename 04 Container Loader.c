#include <stdio.h>
#include <stdbool.h>
#define MAX_CONTAINERS 100
#define MAX_ITEMS 100
int containers[MAX_CONTAINERS];
int items[MAX_ITEMS];
int numContainers, numItems;
void containerLoading() {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = i + 1; j < numItems; j++) {
            if (items[i] < items[j]) {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    int containerIndex = 0;
    for (int i = 0; i < numContainers; i++) {
        containers[i] = 0;
    }
    for (int i = 0; i < numItems; i++) {
        bool placed = false;
        for (int j = 0; j <= containerIndex; j++) {
            if (containers[j] + items[i] <= 100) { 
                containers[j] += items[i];
                placed = true;
                break;
            }
        }

        if (!placed) {
            containerIndex++;
            containers[containerIndex] = items[i];
        }
    }
    printf("Container Loading Result:\n");
    for (int i = 0; i <= containerIndex; i++) {
        printf("Container %d: %d/%d\n", i + 1, containers[i], 100);
    }
}

int main() {
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the sizes of items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    containerLoading();

    return 0;
}
