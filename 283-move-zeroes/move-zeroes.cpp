class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonzero = 0;
        for (int i = 0; i<nums.size();i++){
            if(nums[i] !=  0){
                nums[lastnonzero] = nums[i];
                lastnonzero++;
            }
        }
        for (int i = lastnonzero; i< nums.size(); i++){
            nums[i]=0;
        } 
    }
};