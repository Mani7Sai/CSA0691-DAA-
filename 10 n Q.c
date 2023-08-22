#include <stdio.h>
#include <stdbool.h>
bool isSafe(int board[][100], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(int board[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool solveNQueens(int board[][100], int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;

    printf("Enter the board size (N): ");
    scanf("%d", &n);

    int board[100][100] = {0};

    if (!solveNQueens(board, 0, n)) {
        printf("No solution exists for N=%d.\n", n);
    }

    return 0;
}
