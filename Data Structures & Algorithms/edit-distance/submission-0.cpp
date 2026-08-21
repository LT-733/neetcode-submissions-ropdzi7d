class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string word1, string word2, int i, int j){
        if(j == word2.size()) return word1.size() - i;
        // if(i >= word1.size() or j >= word2.size()) return INT_MAX;
        if(i == word1.size()) return word2.size() - j;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INT_MAX-1;
        if(word1[i] == word2[j]){
            dp[i][j] = min(dp[i][j], dfs(word1, word2, i+1, j+1));
        }else{
            dp[i][j] = min(dp[i][j], 1 + dfs(word1, word2, i+1, j+1));
            dp[i][j] = min(dp[i][j], 1 + dfs(word1, word2, i, j+1));
            dp[i][j] = min(dp[i][j], 1 + dfs(word1, word2, i+1, j));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(), vector<int> (word2.size(), -1));
        return dfs(word1, word2, 0, 0);
    }
};
