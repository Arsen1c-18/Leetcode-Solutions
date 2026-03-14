int longestArithSeqLength(int* nums, int numsSize) {
    int dp[numsSize][1001];
    
    for(int i=0;i<numsSize;i++)
        for(int j=0;j<1001;j++)
            dp[i][j]=0;

    int max=0;

    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++){
            int diff = nums[i] - nums[j] + 500;

            dp[i][diff] = dp[j][diff] + 1;

            if(dp[i][diff] > max)
                max = dp[i][diff];
        }
    }

    return max + 1;
}