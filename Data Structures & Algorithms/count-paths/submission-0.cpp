class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int m, int n){
        // cout<<m<<" "<<n<<"\n";
        if(m >= dp.size() or n >= dp[0].size()) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(m == dp.size()-1 and n == dp[0].size()-1){
            // cout<<"reached it\n";
            return 1;
        }
        dp[m][n] = 0;
        // cout<<"hey\n";
        if(m+1 < dp.size() and dp[m+1][n] == -1){
            dp[m+1][n] = dfs(m+1, n);
        }if(n+1 < dp[0].size() and dp[m][n+1] == -1){
            dp[m][n+1] = dfs(m, n+1);
        }
        if(m + 1 < dp.size()){
            dp[m][n] += dp[m+1][n];
        }if(n + 1 < dp[0].size()){
            dp[m][n] += dp[m][n+1];
        }
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int> (n, -1));
        int result = dfs(0, 0);
        return result;
    }
};
