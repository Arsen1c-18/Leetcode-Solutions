class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> element;
        int x;
        for (int i = 0; i < nums.size(); i++){
            x = target - nums[i];
            if(element.find(x) != element.end() && element[x] != i){
                return {element[x],i};  
            }
            element[nums[i]] = i;
        }
        return {}; 
    } 
};