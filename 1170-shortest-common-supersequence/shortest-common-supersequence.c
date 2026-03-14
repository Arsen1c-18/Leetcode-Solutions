char* shortestCommonSupersequence(char* str1, char* str2) {
    int m = strlen(str1), n = strlen(str2);
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]= dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }

    int i=m,j=n,k;
    char *res = malloc(m+n+1);
    k=m+n;
    res[k--]='\0';

    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            res[k--]=str1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            res[k--]=str1[--i];
        else
            res[k--]=str2[--j];
    }

    while(i>0) res[k--]=str1[--i];
    while(j>0) res[k--]=str2[--j];

    return res+k+1;
}