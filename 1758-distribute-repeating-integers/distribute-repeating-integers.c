#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    return *(int*)b - *(int*)a;
}

bool dfs(int* freq,int freqSize,int* quantity,int qSize,int idx){

    if(idx==qSize) return true;

    for(int i=0;i<freqSize;i++){

        if(freq[i] >= quantity[idx]){

            freq[i] -= quantity[idx];

            if(dfs(freq,freqSize,quantity,qSize,idx+1))
                return true;

            freq[i] += quantity[idx];
        }
    }

    return false;
}

bool canDistribute(int* nums,int numsSize,int* quantity,int quantitySize){

    int count[1001]={0};

    for(int i=0;i<numsSize;i++)
        count[nums[i]]++;

    int freq[50];
    int f=0;

    for(int i=0;i<=1000;i++)
        if(count[i])
            freq[f++]=count[i];

    qsort(quantity,quantitySize,sizeof(int),cmp);

    return dfs(freq,f,quantity,quantitySize,0);
}