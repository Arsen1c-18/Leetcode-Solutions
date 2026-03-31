#include <stdlib.h>

int dfs(int** grid, int r, int c, int m, int n, int remain) {

    if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == -1)
        return 0;

    if(grid[r][c] == 2)
        return remain == 1;

    int temp = grid[r][c];
    grid[r][c] = -1;

    int paths =
        dfs(grid,r+1,c,m,n,remain-1) +
        dfs(grid,r-1,c,m,n,remain-1) +
        dfs(grid,r,c+1,m,n,remain-1) +
        dfs(grid,r,c-1,m,n,remain-1);

    grid[r][c] = temp;

    return paths;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int startR, startC;
    int count = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] != -1) count++;
            if(grid[i][j] == 1){
                startR = i;
                startC = j;
            }
        }
    }

    return dfs(grid,startR,startC,m,n,count);
}