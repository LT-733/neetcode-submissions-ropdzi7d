class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(const auto& time : times){
            adj[time[0]];
            adj[time[0]].emplace_back(time[2], time[1]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        int res = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto cur = pq.top();
            int cost = cur.first, node = cur.second;
            pq.pop();
            // if(node == )
            if(visited.count(node)) continue;
            visited.insert(node);
            res = cost;
            for(const auto& p : adj[node]){
                int nextcost = p.first, nextnode = p.second;
                if(visited.count(nextnode)) continue;
                pq.push({nextcost + cost, nextnode});
            }
        }
        return visited.size() != n ? -1 :res;
    }
};
