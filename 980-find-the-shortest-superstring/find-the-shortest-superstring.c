#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int max(int a,int b){ return a>b?a:b; }

char * shortestSuperstring(char ** words, int wordsSize){

    int overlap[12][12];

    for(int i=0;i<wordsSize;i++){
        for(int j=0;j<wordsSize;j++){

            if(i==j) continue;

            int len1=strlen(words[i]);
            int len2=strlen(words[j]);

            int m = len1 < len2 ? len1 : len2;

            for(int k=m;k>=0;k--){

                if(strncmp(words[i]+len1-k,words[j],k)==0){
                    overlap[i][j]=k;
                    break;
                }
            }
        }
    }

    int N = 1<<wordsSize;

    int dp[4096][12];
    int parent[4096][12];

    for(int i=0;i<N;i++)
        for(int j=0;j<wordsSize;j++)
            dp[i][j]=INT_MAX;

    for(int i=0;i<wordsSize;i++)
        dp[1<<i][i]=strlen(words[i]);

    for(int mask=0;mask<N;mask++){

        for(int j=0;j<wordsSize;j++){

            if(!(mask&(1<<j))) continue;

            int prevMask = mask^(1<<j);

            if(prevMask==0) continue;

            for(int i=0;i<wordsSize;i++){

                if(!(prevMask&(1<<i))) continue;

                int val = dp[prevMask][i] +
                          strlen(words[j]) -
                          overlap[i][j];

                if(val < dp[mask][j]){

                    dp[mask][j]=val;
                    parent[mask][j]=i;
                }
            }
        }
    }

    int mask=N-1;
    int last=0;

    for(int i=1;i<wordsSize;i++)
        if(dp[mask][i] < dp[mask][last])
            last=i;

    int path[12];
    int idx=0;

    while(mask){

        path[idx++]=last;

        int temp=parent[mask][last];

        mask^=(1<<last);

        last=temp;
    }

    char* res = malloc(1000);
    strcpy(res, words[path[idx-1]]);

    for(int i=idx-2;i>=0;i--){

        int j=path[i];
        int k=overlap[path[i+1]][j];

        strcat(res, words[j]+k);
    }

    return res;
}