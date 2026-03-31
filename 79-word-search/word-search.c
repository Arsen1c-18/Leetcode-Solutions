#include <stdbool.h>

bool dfs(char** board, int m, int n, int r, int c, char* word, int index) {
    if(word[index] == '\0')
        return true;

    if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[index])
        return false;

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(board,m,n,r+1,c,word,index+1) ||
                 dfs(board,m,n,r-1,c,word,index+1) ||
                 dfs(board,m,n,r,c+1,word,index+1) ||
                 dfs(board,m,n,r,c-1,word,index+1);

    board[r][c] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(dfs(board, m, n, i, j, word, 0))
                return true;
        }
    }

    return false;
}