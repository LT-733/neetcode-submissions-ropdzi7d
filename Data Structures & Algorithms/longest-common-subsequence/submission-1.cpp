class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string text1, string text2, int m, int n){
        if(m >= text1.size() or n >= text2.size()) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        dp[m][n] = 0;
        if(text1[m] == text2[n]){
            if(m < text1.size()-1 and n < text2.size()-1){
                if(dp[m+1][n+1] == -1){
                    dp[m+1][n+1] = dfs(text1, text2, m+1, n+1);
                }
                dp[m][n] = 1 + dp[m+1][n+1];
            }else{
                dp[m][n] = 1;
            }
        }else{
            if(m < text1.size()-1){
                if(dp[m+1][n] == -1){
                    dp[m+1][n] = dfs(text1, text2, m+1, n);
                }
            }
            if(n < text2.size()-1){
                if(dp[m][n+1] == -1){
                    dp[m][n+1] = dfs(text1, text2, m, n+1);
                }
            }
            if(m < text1.size()-1 and n < text2.size()-1){
                dp[m][n] = max(dp[m][n+1], dp[m+1][n]);
            }else {
                if(m < text1.size()-1) dp[m][n] = dp[m+1][n];
                if(n < text2.size()-1) dp[m][n] = dp[m][n+1];
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int> (text2.size(), -1));
        int result = dfs(text1, text2, 0, 0);
        return result;
    }
};
