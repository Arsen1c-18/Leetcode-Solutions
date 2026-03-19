class Solution {
public:
    string toLowerCase(string s) {
        string result;
        for (auto p: s ){
            result += tolower(p);
        }
    return result;
    }
};