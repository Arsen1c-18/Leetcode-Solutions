
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cost = prices[i];
            for (int j = i + 1; j <= min(n, i + i + 2); j++) {
                dp[i] = min(dp[i], cost + dp[j]);
            }
        }
        return dp[0];
    }
};