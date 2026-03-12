class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];
        for (int i =1; i<nums.size();i++){
            if(current_sum + nums[i] >= nums[i]){
                current_sum = current_sum + nums[i];
            }else{
                current_sum = nums[i];
            }
            if(current_sum >= max_sum){
                max_sum=current_sum;
            }
            
        }
    return max_sum;
    }

};