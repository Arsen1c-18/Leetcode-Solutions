#include <stdlib.h>
#include <string.h>

int* smallestSufficientTeam(char** req_skills, int req_skillsSize,
                            char*** people, int peopleSize,
                            int* peopleColSize, int* returnSize){

    int skillMask[60]={0};

    for(int i=0;i<peopleSize;i++){
        for(int j=0;j<peopleColSize[i];j++){
            for(int k=0;k<req_skillsSize;k++){
                if(strcmp(people[i][j],req_skills[k])==0){
                    skillMask[i] |= (1<<k);
                }
            }
        }
    }

    int N = 1<<req_skillsSize;

    int dpSize[N];
    int team[N][60];

    for(int i=0;i<N;i++)
        dpSize[i]=1000;

    dpSize[0]=0;

    for(int i=0;i<peopleSize;i++){

        int pMask = skillMask[i];

        for(int mask=0;mask<N;mask++){

            if(dpSize[mask]==1000)
                continue;

            int newMask = mask | pMask;

            if(dpSize[newMask] > dpSize[mask]+1){

                for(int t=0;t<dpSize[mask];t++)
                    team[newMask][t] = team[mask][t];

                team[newMask][dpSize[mask]] = i;

                dpSize[newMask] = dpSize[mask]+1;
            }
        }
    }

    int fullMask = N-1;

    *returnSize = dpSize[fullMask];

    int* res = malloc((*returnSize)*sizeof(int));

    for(int i=0;i<*returnSize;i++)
        res[i] = team[fullMask][i];

    return res;
}