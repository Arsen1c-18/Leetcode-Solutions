class Solution {
public:
    bool check(vector<int>& nums) {
        int drop_count=0;
        for ( int i = 0; i<nums.size(); i++){
            if(nums[i] > nums[(i+1)%nums.size()]){
                drop_count++;
            }
        }
        return drop_count<=1;
    }
};