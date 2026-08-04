class Solution {
public:
    // int result;
    // void coinChange(vector<int>& coins, int amount, int curcoins, int i){
    //     if(i >= coins.size()) return;
    //     if (amount - coins[i] == 0){
    //         result = min(curcoins+1, result);
    //         return;
    //     }
    //     if (amount - coins[i] < 0) return;
    //     coinChange(coins, amount - coins[i], curcoins+1, i);
    //     coinChange(coins, amount, curcoins, i+1);
    // }
    unordered_map<int, int> dp;
    int dfs(vector<int>& coins, int amount){
        if(!amount) return 0;
        if(dp.find(amount) != dp.end()) return dp[amount];
        int temp = INT_MAX;
        for(int i = 0; i < coins.size(); ++i){
            if(amount - coins[i] >= 0){
                int cur = dfs(coins, amount - coins[i]);
                if(cur != INT_MAX)
                    temp = min(1 + cur, temp);
            }
        }
        dp[amount] = temp;
        cout<<dp[amount]<<"\n";
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        // result = INT_MAX;
        // coinChange(coins, amount, 0, 0);
        // if(result == INT_MAX) return -1;
        // return result;
        int result = dfs(coins, amount);
        if(result == INT_MAX) return -1;
        return result;
    }
};
