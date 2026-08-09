class Solution {
public:
    vector<int> dp;
    void dfs(vector<int>& nums, int idx){
        if(idx >= nums.size()) return;
        if(dp[idx] != -1) return;
            // cout<<k<<"\n";
        dp[idx]=1;
        for(int i = idx+1; i < nums.size(); ++i){
            // cout<<"i "<<i<<"\n";
            if(nums[i] > nums[idx]){
                if(dp[i] == -1){
                    dfs(nums, i);
                }
                dp[idx] = max(dp[idx], 1 + dp[i]);
                // cout<<dp[k]<<"\n";
            }
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        for(int i = 0; i < nums.size(); ++i){
            dfs(nums, i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
