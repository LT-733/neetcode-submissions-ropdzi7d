class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(vector<int>& nums, int target, int idx){
        // cout<<"target: "<<target<<"\n";
        if (idx == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        dp[idx][target]=dfs(nums, target, idx+1) or dfs(nums, target - nums[idx], idx+1);
        return dp[idx][target];
    }
    bool canPartition(vector<int>& nums) {
        if(reduce(nums.begin(), nums.end()) % 2) return false;
        int target = reduce(nums.begin(), nums.end()) / 2;
        dp.resize(nums.size(), vector<int>(target +1, -1));
        // cout<<target<<endl;
        return dfs(nums, target, 0);
    }
};
