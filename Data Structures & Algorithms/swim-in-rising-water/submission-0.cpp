class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // visited[0][0] = true;
        // int i = 0, j = 0;
        set<vector<int>> visited;
        visited.insert({grid[0][0], 0, 0});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            // if(visited.count(cur)) continue;
            if(cur[1] == grid.size()-1 and cur[2] == grid[0].size()-1) return cur[0];
            for(auto d : dir){
                int i = cur[1] + d.first, j = cur[2]+d.second;
                if(i >= grid.size() or i < 0 or j >= grid[0].size() or j < 0) continue;
                vector<int> topush = {max(grid[i][j], cur[0]), i, j};
                if(visited.count(topush)) continue;
                pq.push(topush);
                visited.insert(topush);
            }
        }
        return grid.size()*grid.size();
    }
};
