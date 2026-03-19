class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count_digit=0;
        int count_num=0;

        for ( auto n : nums){
            count_digit = 0;
            while (n!=0){
                n/=10;
                count_digit++;
            }
            if(count_digit%2==0){
                count_num++;
                
            }
        }
        return count_num;
    }
};