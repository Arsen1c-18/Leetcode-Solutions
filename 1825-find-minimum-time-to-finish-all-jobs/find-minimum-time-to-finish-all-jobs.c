#include <stdlib.h>
#include <stdbool.h>

bool backtrack(int* jobs, int jobsSize, int* workers, int k, int idx, int limit){
    
    if(idx == jobsSize)
        return true;

    for(int i = 0; i < k; i++){

        if(workers[i] + jobs[idx] <= limit){

            workers[i] += jobs[idx];

            if(backtrack(jobs, jobsSize, workers, k, idx + 1, limit))
                return true;

            workers[i] -= jobs[idx];
        }

        if(workers[i] == 0)
            break;
    }

    return false;
}

int minimumTimeRequired(int* jobs, int jobsSize, int k){

    int maxJob = 0;
    int sum = 0;

    for(int i = 0; i < jobsSize; i++){
        if(jobs[i] > maxJob)
            maxJob = jobs[i];
        sum += jobs[i];
    }

    int left = maxJob;
    int right = sum;

    while(left < right){

        int mid = (left + right) / 2;

        int* workers = calloc(k, sizeof(int));

        if(backtrack(jobs, jobsSize, workers, k, 0, mid))
            right = mid;
        else
            left = mid + 1;

        free(workers);
    }

    return left;
}