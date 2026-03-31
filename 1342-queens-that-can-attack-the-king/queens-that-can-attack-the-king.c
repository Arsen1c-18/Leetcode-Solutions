#include <stdlib.h>

int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize,
                          int* king, int kingSize,
                          int* returnSize, int** returnColumnSizes) {

    int board[8][8] = {0};

    for (int i = 0; i < queensSize; i++)
        board[queens[i][0]][queens[i][1]] = 1;

    int dirs[8][2] = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{1,-1},{-1,1},{-1,-1}
    };

    int **res = malloc(sizeof(int*) * 8);
    *returnColumnSizes = malloc(sizeof(int) * 8);
    *returnSize = 0;

    for (int d = 0; d < 8; d++) {
        int r = king[0];
        int c = king[1];

        while (1) {
            r += dirs[d][0];
            c += dirs[d][1];

            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                break;

            if (board[r][c]) {
                res[*returnSize] = malloc(sizeof(int) * 2);
                res[*returnSize][0] = r;
                res[*returnSize][1] = c;

                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
                break;
            }
        }
    }

    return res;
}