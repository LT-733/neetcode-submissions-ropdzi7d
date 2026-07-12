class Solution {
public:
    vector<vector<int>> results;
    void dfs(int curidx, vector<int>& nums, int target, vector<int>& cur) {
        if(reduce(cur.begin(), cur.end()) > target) return;
        if(reduce(cur.begin(), cur.end()) == target){
            results.push_back(cur);
            return;
        }
        for(int j = curidx; j < nums.size(); ++j){
            cur.push_back(nums[j]);
            dfs(j, nums, target, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target){
        vector<int> cur = {};
        dfs(0, nums, target, cur);
        return results;
    }
};
