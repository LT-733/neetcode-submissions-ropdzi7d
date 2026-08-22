class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int l, int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for(int x = l; x <= r; ++x){
            int cur = nums[l-1] * nums[x] * nums[r+1];
            cur += dfs(nums, l, x-1) + dfs(nums, x+1, r);
            dp[l][r] = max(cur, dp[l][r]);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int> padded_nums(nums.size()+2, 1);
        for(int i = 0; i < nums.size(); ++i){
            padded_nums[i+1] = nums[i];
        }
        dp.resize(padded_nums.size(), vector<int> (padded_nums.size(), -1));
        return dfs(padded_nums, 1, nums.size());
    }
};
