class Solution {
public:
    map<pair<int, bool>, int> dp;
    int dfs(vector<int>& prices, int idx, bool canbuy){
        if(idx >= prices.size()) return 0;
        auto state = make_pair(idx, canbuy);
        if(dp.find(state) != dp.end()) return dp[state];
        int standby = dfs(prices, idx+1, canbuy);
        if(canbuy){
            int bought = dfs(prices, idx+1, false) - prices[idx];
            dp[state] = max(bought, standby);
        } else{
            int sold = dfs(prices, idx+2, true) + prices[idx];
            dp[state] = max(sold, standby);
        }
        return dp[state];
    }
    int maxProfit(vector<int>& prices) {
        int result = dfs(prices, 0, true);
        return result;
    }
};
