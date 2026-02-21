
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen[c - 'a']) continue;
            while (!st.empty() && st.top() > c && last[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            seen[c - 'a'] = true;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};