class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unordered_map<int, vector<pair<int, int>>> neighbors;
        for(auto time : times){
            neighbors[time[0]].emplace_back(time[1], time[2]);
        }
        pq.push({0, k});
        unordered_set<int> visited;
        int time = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cost = cur.first, node = cur.second;
            if(visited.count(node)) continue;
            visited.insert(node);
            time = cost;
            for(auto neighbor : neighbors[node]){
                if(visited.count(neighbor.first)) continue;
                pq.push({neighbor.second + time, neighbor.first});
            }
        }
        return visited.size() < n ? -1 : time;
    }
};
