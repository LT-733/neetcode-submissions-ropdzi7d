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
        int curtime = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(visited.count(cur.second)) continue;
            visited.insert(cur.second);
            curtime = cur.first;
            if(neighbors.find(cur.second) != neighbors.end()) {
                for(const auto& edge : neighbors[cur.second]){
                    if(!visited.count(edge.first)){
                        pq.push({edge.second + curtime, edge.first});
                    }
                }
            }
        }
        return visited.size() == n ? curtime : -1;
    }
};
