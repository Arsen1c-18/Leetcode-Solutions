#include <limits.h>

int minimumXORSum(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int n = nums1Size;
    int dp[1<<14];

    for(int i=0;i<(1<<n);i++) dp[i]=INT_MAX;
    dp[0]=0;

    for(int mask=0;mask<(1<<n);mask++){

        int i = __builtin_popcount(mask);

        for(int j=0;j<n;j++){
            if(!(mask&(1<<j))){
                int next = mask|(1<<j);

                int val = dp[mask] + (nums1[i]^nums2[j]);

                if(val < dp[next])
                    dp[next] = val;
            }
        }
    }

    return dp[(1<<n)-1];
}