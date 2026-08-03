class Solution {
public:
    vector<int> dp;
    int dfs(string& s, int idx){
        if (idx == s.size()) {
            return 1;
        }
        if(idx > s.size()) return 0;
        // dfs(s, idx+1);
        // dfs(s, idx+2);
        if(dp[idx] == -1){
            if(s[idx] == '0') {dp[idx] = 0; return 0;}
            dp[idx] = dfs(s, idx+1);
            if(idx < s.size()-1 and (s[idx] - '0')*10 + (s[idx+1]-'0') > 26) return dp[idx];
            dp[idx] += dfs(s, idx+2);
        }
        return dp[idx];
    }
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return dfs(s, 0);
    }
};
