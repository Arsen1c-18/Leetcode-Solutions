class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> s1(s.begin(),s.end());
        vector<char> s2(t.begin(),t.end());
        if(s.length()!=t.length()){
            return false;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i = 0; i< s.length();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
    return true;
    }
};