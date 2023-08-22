#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int list[n];

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    printf("Minimum and Maximum Value Subsequences:\n");

    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int j = i; j < n; j++) {
            if (list[j] < minVal) {
                minVal = list[j];
            }
            if (list[j] > maxVal) {
                maxVal = list[j];
            }

            printf("For number %d: Min: %d, Max: %d\n", list[i], minVal, maxVal);
        }
    }

    return 0;
}
