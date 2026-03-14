int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    int dp[n][n];

    for(int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;

        for(int j = i+1; j < n; j++) {
            if(s[i] == s[j]) {
                if(j == i+1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1];
            }
        }
    }

    return dp[0][n-1];
}