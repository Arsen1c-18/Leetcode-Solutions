class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int maxLength = max(word1.length(),word2.length());
        string merged;
        for (int i = 0 ; i < maxLength; i++){
            if(i<word1.length()){
                merged.push_back(word1[i]);
            }
            if(i<word2.length()){
                merged.push_back(word2[i]);
            }
        }
        return merged;
    }
};