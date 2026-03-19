class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = nums[0];
        vector<int> result(nums.size());
        result[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            result[i] = sum;
        }
    return result;
    }
};