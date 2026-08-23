class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int amount, vector<int>& coins, int idx){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(idx >= coins.size()) return 0;
        if(dp[amount][idx] != -1) return dp[amount][idx];
        dp[amount][idx] = 0;
        dp[amount][idx] += dfs(amount - coins[idx], coins, idx) + dfs(amount, coins, idx+1);
        return dp[amount][idx];
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, 0);
    }
};
