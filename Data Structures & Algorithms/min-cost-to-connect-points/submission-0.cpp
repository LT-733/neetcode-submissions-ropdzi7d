class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> neighbors;
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                int price = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                neighbors[i].push_back({price, j});
                neighbors[j].push_back({price, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        unordered_set<int> visited;
        // visited.insert(0);
        int cost = 0;
        while(visited.size() < points.size()){
            auto next = pq.top();
            pq.pop();
            if(visited.count(next.second)) continue;
            cost += next.first;
            visited.insert(next.second);
            for(auto costtopt : neighbors[next.second]){
                if(!visited.count(costtopt.second)) pq.push(costtopt);
            }
        }
        return cost;
    }
};
