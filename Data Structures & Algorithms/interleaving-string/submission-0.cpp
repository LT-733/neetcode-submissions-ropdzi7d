class Solution {
public:
    map<pair<int, int>, bool> dp;
    bool dfs(string s1, string s2, string s3, int idx1, int idx2, int idx3){
        if(idx3 >= s3.size()) return true;
        auto state = make_pair(idx1, idx2);
        // if(idx3 == s3.size()-1 and (s3[idx3] == s2[idx2] or s3[idx3] == s1[idx1])) return true;
        if(dp.find(state) != dp.end()) return dp[state];
        else{
            dp[state] = false;
            if(s3[idx3] != s1[idx1] and s3[idx3] != s2[idx2]) return false;
            else{
                if(s3[idx3] == s1[idx1] and s3[idx3] == s2[idx2]){
                    dp[state] = dp[state] or (dfs(s1, s2, s3, idx1+1, idx2, idx3+1) or dfs(s1, s2, s3, idx1, idx2+1, idx3+1));
                }
                else if(s3[idx3] == s1[idx1]){
                    dp[state] = dp[state] or dfs(s1, s2, s3, idx1+1, idx2, idx3+1);
                }
                else if(s3[idx3] == s2[idx2]){
                    dp[state] = dp[state] or dfs(s1, s2, s3, idx1, idx2+1, idx3+1);
                }
            }
        }
        return dp[state];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        if(s3.size() == 0 and (s1.size() or s2.size())) return false;
        if(s3.size() == 0 and !(s1.size() or s2.size())) return true;
        return dfs(s1, s2, s3, 0, 0, 0);
    }
};
