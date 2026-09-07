class Solution {
public:
    vector<string> result;
    void dfs(string cur, unordered_map<string, vector<string>>& adj){
        while(adj[cur].size()!= 0){
            string last = adj[cur].back();
            adj[cur].pop_back();
            dfs(last, adj);
        }
        result.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(auto ticket : tickets){
            adj[ticket[0]];
            adj[ticket[0]].emplace_back(ticket[1]);
        }
        for(auto& [node, neighbors] : adj){
            sort(neighbors.rbegin(), neighbors.rend());
        }
        dfs("JFK", adj);
        reverse(result.begin(), result.end());
        return result;
    }
};
