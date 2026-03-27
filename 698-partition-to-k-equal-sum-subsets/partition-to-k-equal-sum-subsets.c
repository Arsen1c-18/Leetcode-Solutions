int dfs(int* nums,int numsSize,int* vis,int start,int k,int cur,int target){

    if(k==1) return 1;

    if(cur==target)
        return dfs(nums,numsSize,vis,0,k-1,0,target);

    for(int i=start;i<numsSize;i++){

        if(!vis[i] && cur+nums[i]<=target){

            vis[i]=1;

            if(dfs(nums,numsSize,vis,i+1,k,cur+nums[i],target))
                return 1;

            vis[i]=0;
        }
    }

    return 0;
}

int canPartitionKSubsets(int* nums,int numsSize,int k){

    int sum=0;

    for(int i=0;i<numsSize;i++) sum+=nums[i];

    if(sum%k) return 0;

    int vis[20]={0};

    return dfs(nums,numsSize,vis,0,k,0,sum/k);
}