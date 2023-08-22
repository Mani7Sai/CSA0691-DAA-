#include <stdio.h>
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}
void printPascalsTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            int coef = binomialCoefficient(i, j);
            printf("%d ", coef);
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    if (numRows <= 0) {
        printf("Please enter a positive number of rows.\n");
    } else {
        printf("Pascal's Triangle with %d rows:\n", numRows);
        printPascalsTriangle(numRows);
    }

    return 0;
}