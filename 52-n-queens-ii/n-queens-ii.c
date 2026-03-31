int count;

void solve(int row, int n, int *cols, int *diag1, int *diag2) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            continue;

        cols[col] = 1;
        diag1[row - col + n - 1] = 1;
        diag2[row + col] = 1;

        solve(row + 1, n, cols, diag1, diag2);

        cols[col] = 0;
        diag1[row - col + n - 1] = 0;
        diag2[row + col] = 0;
    }
}

int totalNQueens(int n) {
    int cols[n];
    int diag1[2*n];
    int diag2[2*n];

    for(int i = 0; i < n; i++) cols[i] = 0;
    for(int i = 0; i < 2*n; i++) {
        diag1[i] = 0;
        diag2[i] = 0;
    }

    count = 0;
    solve(0, n, cols, diag1, diag2);

    return count;
}