class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string res;
    bool dfs(char c){
        if(visited.count(c)) return visited[c];
        visited[c] = true;
        for(auto ch : adj[c]){
            if(dfs(ch)) return true;
        }
        visited[c] = false;
        res += c;
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        for(string& word : words){
            for(char c : word){
                adj[c];
            }
        }
        for(int i = 0; i < words.size()-1; ++i){
            int cur = i, next = i+1;
            // int wordidx = 0;
            int len = min(words[cur].size(), words[next].size());
            if(words[cur].length() > words[next].length() and words[cur].substr(0, len) == words[next].substr(0, len)) return "";
            for(int j = 0; j < len; ++j){
                if(words[cur][j] != words[next][j]){
                    adj[words[cur][j]].insert(words[next][j]); break;
                }
            }
        }
        for(const auto& [c, s] : adj){
            if(dfs(c)) return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
