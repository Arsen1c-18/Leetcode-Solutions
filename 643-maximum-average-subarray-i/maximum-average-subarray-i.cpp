class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        
        for (int right = 0; right < k; right++){
            sum += nums[right];
        }
        int max = sum;
        for (int right = k; right < nums.size(); right++){
                sum = sum - nums[left];
                sum = sum + nums[right];
                left++;
            if(sum > max){
                max = sum;
            }
        }
        double avg = max;
        return avg/k;
    }
};