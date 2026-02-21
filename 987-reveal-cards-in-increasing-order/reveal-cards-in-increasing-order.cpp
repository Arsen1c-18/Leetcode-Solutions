
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < deck.size(); i++) q.push(i);
        vector<int> res(deck.size());
        for (int x : deck) {
            int idx = q.front(); q.pop();
            res[idx] = x;
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};