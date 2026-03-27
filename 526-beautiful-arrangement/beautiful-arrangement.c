int dfs(int n, int mask, int* dp){

    if(mask == (1<<n)-1)
        return 1;

    if(dp[mask] != -1)
        return dp[mask];

    int pos = __builtin_popcount(mask) + 1;
    int ans = 0;

    for(int i=0;i<n;i++){

        if(!(mask&(1<<i))){

            int num = i + 1;

            if(num % pos == 0 || pos % num == 0)
                ans += dfs(n, mask|(1<<i), dp);
        }
    }

    return dp[mask] = ans;
}

int countArrangement(int n){

    int size = 1<<n;
    int dp[size];

    for(int i=0;i<size;i++)
        dp[i] = -1;

    return dfs(n,0,dp);
}