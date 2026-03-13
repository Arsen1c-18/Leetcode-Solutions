class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int x = s.size();
        nums.assign(s.begin(),s.end());
        return x;
        
    }
};