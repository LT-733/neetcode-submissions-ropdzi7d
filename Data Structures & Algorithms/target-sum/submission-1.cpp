class Solution {
public:
    map<pair<int, int>, int> dp;
    // void dfs(vector<int>& nums, int target, int idx){
    //     // if(0 == target) ++numres;
    //     if(idx >= nums.size()) {
    //         numres += (target == 0);
    //         return;
    //     }
    //     dfs(nums, target - nums[idx], idx+1);
    //     dfs(nums, target + nums[idx], idx+1);
    // }
    int dfs(vector<int>& nums, int target, int idx, int cursum){
        if(idx >= nums.size()){
            return cursum==target;
        }
        auto state = make_pair(idx, cursum);
        if(dp.find(state) != dp.end()) return dp[state];
        else{
            dp[state] = dfs(nums, target, idx+1, cursum+nums[idx]) + dfs(nums, target, idx+1, cursum-nums[idx]);
        }
        return dp[state];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // numres = 0;
        // dfs(nums, target, 0);
        // return numres;
        return dfs(nums, target, 0, 0);
    }
};
