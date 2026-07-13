class Solution {
public:
    vector<vector<int>> result = {{}};
    void dfs(vector<int>& nums, vector<int>& cur, int idx){
        if(idx == nums.size()) return;
        cur.push_back(nums[idx]);
        result.push_back(cur);
        dfs(nums, cur, idx+1);
        cur.pop_back();
        dfs(nums, cur, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur = {};
        dfs(nums, cur, 0);
        return result;
    }
};
