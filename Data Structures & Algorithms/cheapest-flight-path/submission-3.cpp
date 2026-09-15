class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto flight : flights){
            adj[flight[0]];
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> cost(n+1, INT_MAX);
        cost[src] = 0;
        // int cur = 0;
        for(int i = 0; i <= k; ++i){
            vector<int> temp(cost.begin(), cost.end());
            for(int j = 0; j < temp.size(); ++j){
                if(cost[j] == INT_MAX) continue;
                for(const auto& p : adj[j]){
                    if(cost[j] + p.second < temp[p.first]){
                        temp[p.first] = cost[j] + p.second;
                        cout<<temp[dst]<<"\n";
                    }
                }
            }
            cost = temp;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
