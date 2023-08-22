#include <stdio.h>
int main() {
    int originalArray[100]; 
    int newArray[101];      
    int n, num, pos, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &originalArray[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position to insert (0-%d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Invalid position. Position should be between 0 and %d\n", n);
        return 1; 
    }
    for (i = 0; i < pos; i++) {
        newArray[i] = originalArray[i];
    }
    newArray[pos] = num;
    for (i = pos; i < n; i++) {
        newArray[i + 1] = originalArray[i];
    }
    n++;
    printf("Updated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", newArray[i]);
    }
    return 0; 
}
