#include <stdlib.h>

int max(int a,int b){ return a>b?a:b; }

int countBits(int x){
    int c=0;
    while(x){
        c+=x&1;
        x>>=1;
    }
    return c;
}

int maxStudents(char** seats, int seatsSize, int* seatsColSize){

    int m = seatsSize;
    int n = seatsColSize[0];
    int maxMask = 1<<n;

    int dp[9][256];

    for(int i=0;i<9;i++)
        for(int j=0;j<256;j++)
            dp[i][j] = -1;

    dp[0][0] = 0;

    for(int r=1;r<=m;r++){

        for(int mask=0;mask<maxMask;mask++){

            if(mask&(mask<<1))
                continue;

            int valid=1;

            for(int c=0;c<n;c++){
                if((mask&(1<<c)) && seats[r-1][c]=='#'){
                    valid=0;
                    break;
                }
            }

            if(!valid)
                continue;

            for(int pm=0;pm<maxMask;pm++){

                if(dp[r-1][pm] < 0)
                    continue;

                if((mask&(pm<<1)) || (mask&(pm>>1)))
                    continue;

                dp[r][mask] = max(dp[r][mask],
                                  dp[r-1][pm] + countBits(mask));
            }
        }
    }

    int ans = 0;

    for(int mask=0;mask<maxMask;mask++)
        ans = max(ans, dp[m][mask]);

    return ans;
}