class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for (auto& i: nums){
            if(i==1){
                count++;
                maxCount = max(maxCount,count);
            }else if(i==0){
                count = 0;
            }
        }
        return maxCount;
    }
};