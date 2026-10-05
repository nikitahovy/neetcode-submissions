class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int cnt = 0;
        // unordered_map<int, int> div;
        // unordered_map<int, int> rem;

        if (coins.size() == 1) {
            if (amount % coins[0] != 0) {
                return 0;
            }
        }
        // }
        // for (int i = 0; i < coins.size(); i++) {
            

        // }
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int current = coin; current <= amount; current++) {
                dp[current] += dp[current - coin];
            }
        }
        return dp[amount];
    }
};
