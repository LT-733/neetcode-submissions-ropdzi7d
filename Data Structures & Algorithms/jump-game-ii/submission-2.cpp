class Solution {
public:
    vector<int> dp;
    int dfs(int cur, vector<int>& nums){
        if(cur >= nums.size()-1) return 0;
        if(nums[cur] == 0) return -1;
        if(dp[cur] != INT_MAX) return dp[cur];
        dp[cur] = 0;
        int optimal_jump = INT_MAX;
        for(int i = 1; i <= nums[cur]; ++i){
            // cout<<cur<<": "<<i<<"\n";
            int cur_jump = 1 + dfs(cur+i, nums);
            if(cur_jump == 0) continue;
            // cout<<cur_jump<<"\n";
            optimal_jump = min(cur_jump, optimal_jump);
        }
        dp[cur] = optimal_jump;
        return dp[cur];
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), INT_MAX);
        // int tgt = nums.size()-1;
        // int res = 0;
        // for(int i = tgt-1; i >= 0; ){
        //     while(i + nums[i] >= tgt){
        //         // tgt = i;
        //         --i;
        //     }
        //     tgt = i;
        //     ++res;
        //     --i;
        // }
        int res = dfs(0, nums);
        return res;
    }
};
