class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string s, string t, int i, int j){
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        if(s[i] != t[j]){
            dp[i][j] += dfs(s, t, i+1, j);
        }else{
            dp[i][j] += (dfs(s, t, i+1, j) + dfs(s, t, i+1, j+1));
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        dp.resize(s.size(), vector<int> (t.size(), -1));
        return dfs(s, t, 0, 0);
    }
};
