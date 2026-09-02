class Solution {
public:
    vector<vector<int>> neighbors;
    unordered_set<int> incycle;
    int start = -1;
    bool dfs(int node, int prev, vector<bool>& visited){
        // if(node == start) return;
        if(visited[node]) {
            start = node;
            return true;
        }
        visited[node] = true;
        for(int n : neighbors[node]){
            if(n == prev) continue;
            if(dfs(n, node, visited)){
                if(start != -1) incycle.insert(n);
                if(node == start) start = -1;
                return true;
            }
        }return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        neighbors.resize(edges.size()+1, vector<int>());
        for(auto e : edges){
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        vector<bool> visited(edges.size()+1, false);
        dfs(1, -1, visited);
        for(int i = edges.size()-1; i >= 0; --i){
            if(incycle.count(edges[i][0]) and incycle.count(edges[i][1])) return {edges[i][0], edges[i][1]};
        }
        return {};
    }
};
