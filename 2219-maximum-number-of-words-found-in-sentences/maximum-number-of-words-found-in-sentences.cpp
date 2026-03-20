class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_count = 0;
        for(auto& s : sentences){
            int count_word = 1;

            for (auto& c : s){
                if (c == ' '){
                    count_word++;
                }
            }
            if(count_word >= max_count){
                    max_count = count_word;
            }
        }
    return max_count;
    }
};