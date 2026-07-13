class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, vector<int>& cur, int idx, int target, int sum){
        if(sum == target){
            res.push_back(cur);
            return;
        }else if(sum > target || idx == candidates.size()){
            return;
        }else{
            // for(int i = idx+1; i < candidates.size(); ++i){
                cur.push_back(candidates[idx]);
                dfs(candidates, cur, idx+1, target, sum + candidates[idx]);
                cur.pop_back();
                while (idx+1 < candidates.size() && candidates[idx] == candidates[idx + 1]) idx++;
                dfs(candidates, cur, idx+1, target, sum);
            // }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur = {};
        dfs(candidates, cur, 0, target, 0);
        // sort(res.begin(), res.end());
        // auto iterator = unique(res.begin(), res.end());
        // res.resize(distance(res.begin(), iterator));
        return res;
    }
};
