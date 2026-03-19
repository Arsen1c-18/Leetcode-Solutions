class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char> m;
        string result;
        for (int i=0; i<indices.size();i++){
            m[indices[i]] = s[i];   
        }
        for (auto& p: m){
            result += p.second;
        }
    return result;
    }
};