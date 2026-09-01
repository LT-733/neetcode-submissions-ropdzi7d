class Solution {
public:
    
    bool dfs(int node, int prev, vector<vector<int>> neighbors, unordered_set<int>& onpath){
        if(onpath.find(node) != onpath.end()) return false;
        onpath.insert(node);
        for(int n : neighbors[node]){
            if(n == prev) continue;
            if(!dfs(n, node, neighbors, onpath)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> neighbors(n, vector<int>());
        for(auto e : edges){
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        bool res = true;
        unordered_set<int> onpath;
        if(!dfs(0, -1, neighbors, onpath)) return false;
        if(onpath.size() != n) return false;
        return res;
    }
};
