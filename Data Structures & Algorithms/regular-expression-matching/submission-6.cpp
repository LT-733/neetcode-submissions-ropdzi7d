class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string s, string p, int i, int j){
        if(j >= p.size()) return i >= s.size();
        if(dp[i][j] != -1) return dp[i][j];
        else{
            dp[i][j] = false;
            if(i >= s.size()){
                if(j+1 < p.size() and p[j+1] == '*') {
                    dp[i][j] = dp[i][j] or dfs(s, p, i, j+2);
                }
            }else{            
                if(p[j] == '.'){
                    if(j+1 < p.size() and p[j+1] == '*'){
                        dp[i][j] = dp[i][j] or dfs(s, p, i+1, j+2);
                        dp[i][j] = dp[i][j] or dfs(s, p, i, j+2);
                        dp[i][j] = dp[i][j] or dfs(s, p, i+1, j);
                    }
                    else dp[i][j] = dp[i][j] or dfs(s, p, i+1, j+1);
                }else {
                    if(j+1 < p.size() and p[j+1] == '*'){
                        if(s[i] == p[j]){
                            dp[i][j] = dp[i][j] or dfs(s, p, i+1, j+2);
                            dp[i][j] = dp[i][j] or dfs(s, p, i+1, j);
                        }dp[i][j] = dp[i][j] or dfs(s, p, i, j+2);
                    }else{
                        if(s[i] == p[j]){
                            dp[i][j] = dp[i][j] or dfs(s, p, i+1, j+1);
                        }
                    }
                }
            }
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1, vector<int> (p.size()+1, -1));
        return dfs(s, p, 0, 0);
    }
};
