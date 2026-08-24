class Solution {
public:
    int maxArea = 0;
    vector<vector<bool>> visited;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() or j >= grid[0].size() or j < 0 or i < 0) return 0;
        if(visited[i][j]) return 0;
        visited[i][j] = true;
        if(grid[i][j] == 0) return 0;
        int cur = 1;
        cur += dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
        // cout<<"cur: "<<cur<<"\n"; 
        return cur;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited.resize(grid.size(), vector<bool> (grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1 and !visited[i][j]){
                    // cout<<"hey\n";
                    int curmax = dfs(grid, i, j);
                    maxArea = max(maxArea, curmax);
                }
            }
        }
        return maxArea;
    }
};
