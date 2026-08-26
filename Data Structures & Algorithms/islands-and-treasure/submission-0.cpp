class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(i+1 < grid.size() and grid[i+1][j] == INT_MAX) {grid[i+1][j] = grid[i][j]+1; q.push({i+1, j});}
            if(j+1 < grid[0].size() and grid[i][j+1] == INT_MAX) {grid[i][j+1] = grid[i][j]+1; q.push({i, j+1});}
            if(i > 0 and grid[i-1][j] == INT_MAX) {grid[i-1][j] = grid[i][j]+1; q.push({i-1, j});}
            if(j > 0 and grid[i][j-1] == INT_MAX) {grid[i][j-1] = grid[i][j]+1; q.push({i, j-1});}
        }
    }
};
