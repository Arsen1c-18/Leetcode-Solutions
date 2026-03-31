#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** result;
int returnSize;
int* returnColumnSizes;

void solve(int row, int n, char** board, int* cols, int* diag1, int* diag2) {
    
    if (row == n) {
        result[returnSize] = (char**)malloc(sizeof(char*) * n);
        
        for (int i = 0; i < n; i++) {
            result[returnSize][i] = strdup(board[i]);
        }

        returnColumnSizes[returnSize] = n;
        returnSize++;
        return;
    }

    for (int col = 0; col < n; col++) {
        
        if (cols[col] || diag1[row-col+n-1] || diag2[row+col])
            continue;

        board[row][col] = 'Q';

        cols[col] = 1;
        diag1[row-col+n-1] = 1;
        diag2[row+col] = 1;

        solve(row + 1, n, board, cols, diag1, diag2);

        board[row][col] = '.';

        cols[col] = 0;
        diag1[row-col+n-1] = 0;
        diag2[row+col] = 0;
    }
}

char*** solveNQueens(int n, int* returnSizeOut, int** returnColumnSizesOut) {

    result = malloc(sizeof(char**) * 1000);
    returnColumnSizes = malloc(sizeof(int) * 1000);
    returnSize = 0;

    char** board = malloc(sizeof(char*) * n);
    
    for (int i = 0; i < n; i++) {
        board[i] = malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    int cols[n];
    int diag1[2*n];
    int diag2[2*n];

    memset(cols, 0, sizeof(cols));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    solve(0, n, board, cols, diag1, diag2);

    *returnSizeOut = returnSize;
    *returnColumnSizesOut = returnColumnSizes;

    return result;
}