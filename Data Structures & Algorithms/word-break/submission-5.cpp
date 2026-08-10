class Solution {
public:
    unordered_map<string, int> dp;
void dfs(string s, vector<string>& wordDict, int idx){
    if(dp.find(s) != dp.end()) return;
    // cout<<s<<" word\n";
    for(string word : wordDict){
        // cout<<word<<"\n";
        if(s.size() >= word.size() and s.substr(idx - word.size(), word.size()) == word){
            // cout<<"yup\n";
            if(word.size() == s.size()){
                // cout<<"hey\n";
                dp[s] = 1;
            }else if(dp.find(s.substr(0, idx - word.size())) != dp.end() and dp[s.substr(0, idx - word.size())] == 1){
                // cout<<"hello\n";
                dp[s] = 1;
            }else{
                // cout<<s.substr(0, idx - word.size())<<" next one\n";
                dfs(s.substr(0, idx - word.size()), wordDict, idx - word.size());
                if(dp.find(s.substr(0, idx - word.size())) != dp.end() and dp[s.substr(0, idx - word.size())] == 1){
                    dp[s] = 1;
                }else{
                    if(dp.find(s) == dp.end()) dp[s] = -1;
                    // cout<<s<<" -1\n";
                }
            }
        }
    }
}
bool wordBreak(string s, vector<string>& wordDict) {
    dfs(s, wordDict, s.size());
    if(dp.find(s) != dp.end()) return dp.at(s) == 1;
    else return false;
}
};
