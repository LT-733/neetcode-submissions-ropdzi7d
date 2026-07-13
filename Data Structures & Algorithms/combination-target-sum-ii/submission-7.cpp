class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, vector<int>& cur, int idx, int target, int sum){
        if(sum == target){
            res.push_back(cur);
            return;
        }else{
            for(int i = idx; i < candidates.size(); ++i){
                if(i > idx and candidates[i] == candidates[i-1]) continue;
                if(sum + candidates[i] > target) continue;
                cur.push_back(candidates[i]);
                dfs(candidates, cur, i+1, target, sum + candidates[i]);
                cur.pop_back();
            }
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
