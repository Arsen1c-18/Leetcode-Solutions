int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + s1[i-1];
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }

    int total = 0;
    for(int i=0;i<m;i++) total += s1[i];
    for(int i=0;i<n;i++) total += s2[i];

    return total - 2 * dp[m][n];
}