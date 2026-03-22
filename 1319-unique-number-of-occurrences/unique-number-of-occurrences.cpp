class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (auto& num : arr){
            mp[num]++;
        }

        unordered_set<int> s;
        for (auto& n : mp){
            s.insert(n.second);
        }
        return s.size()==mp.size();
    }
};