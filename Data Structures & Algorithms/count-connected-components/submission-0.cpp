class Solution {
public:
    void dfs(int node, int prev, vector<vector<int>> neighbors, vector<int>& visited){
        if(visited[node]) return;
        visited[node] = 1;
        for(int n : neighbors[node]){
            if(n == prev) continue;
            dfs(n, node, neighbors, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> neighbors(n, vector<int>());
        for(auto e : edges){
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        int result = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(i, -1, neighbors, visited);
                ++result;
            }
        }
        return result;
    }
};
