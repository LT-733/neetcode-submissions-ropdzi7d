class Solution {
public:
    vector<vector<int>> results = {{}};
    // bool is_permutation(vector<int> a, vector<int> b){
    //     sort(a.begin(), a.end());
    //     do{
    //         if(a == b) return true;
    //     }while(next_permutation(a.begin(), a.end()));
    //     return false;
    // }
    // void dfs(vector<int>& nums, int idx, vector<int>& cur){
    //     bool alreadyin = false;
    //     cout<<is_permutation({1, 2}, {2, 1})<<endl;
    //     for(auto r : results){
    //         if(is_permutation(r, cur)) alreadyin = true;
    //     }
    //     if(!alreadyin) results.push_back(cur);
    //     if(idx == nums.size()) return;
    //     cur.push_back(nums[idx]);
    //     dfs(nums, idx+1, cur);
    //     cur.pop_back();
    //     dfs(nums, idx+1, cur);
    // }
    void dfs(vector<int>& nums, int i, vector<int>& cur) {
        if(i == nums.size()) return;
        for(int j = i; j < nums.size(); ++j){
            if(j > i and nums[j] == nums[i]) continue;
            cur.push_back(nums[j]);
            results.push_back(cur);
            dfs(nums, j+1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur = {};
        sort(nums.begin(), nums.end());
        dfs(nums, 0, cur);
        sort(results.begin(), results.end());
        auto it = unique(results.begin(), results.end());
        results.resize(distance(results.begin(), it));
        return results;
    }
};
