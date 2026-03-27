int dfs(int** grid,int m,int n,int x,int y,int remain){

    if(grid[x][y]==2){
        if(remain==1) return 1;
        return 0;
    }

    int temp = grid[x][y];
    grid[x][y] = -1;

    int paths = 0;

    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    for(int i=0;i<4;i++){

        int nx=x+d[i][0];
        int ny=y+d[i][1];

        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=-1){

            paths += dfs(grid,m,n,nx,ny,remain-1);
        }
    }

    grid[x][y]=temp;

    return paths;
}

int uniquePathsIII(int** grid,int gridSize,int* gridColSize){

    int m = gridSize;
    int n = gridColSize[0];

    int sx=0,sy=0;
    int cells=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(grid[i][j]!=-1)
                cells++;

            if(grid[i][j]==1){
                sx=i;
                sy=j;
            }
        }
    }

    return dfs(grid,m,n,sx,sy,cells);
}