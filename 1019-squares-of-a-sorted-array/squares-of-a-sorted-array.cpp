class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& p: nums){
            p=p*p;
        }
        sort(nums.begin(),nums.end());
        return nums;
        
    }
};