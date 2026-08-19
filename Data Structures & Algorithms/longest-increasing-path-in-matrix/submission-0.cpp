class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        if(i < matrix.size()-1 and matrix[i+1][j] > matrix[i][j]){
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, i+1, j));
        }
        if(i > 0 and matrix[i-1][j] > matrix[i][j]){
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, i-1, j));
        }
        if(j < matrix[0].size()-1 and matrix[i][j+1] > matrix[i][j]){
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, i, j+1));
        }
        if(j > 0 and matrix[i][j-1] > matrix[i][j]){
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, i, j-1));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};
