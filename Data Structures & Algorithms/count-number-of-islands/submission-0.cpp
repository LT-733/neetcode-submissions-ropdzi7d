class Solution {
public:
    vector<vector<bool>> visited;
    int result=0;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() or j >= grid[0].size() or i < 0 or j < 0) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        if(grid[i][j] == '0'){
            return;
        }else{
            // result += 1;
            dfs(grid, i+1, j);
            dfs(grid, i, j+1);
            dfs(grid, i-1, j);
            dfs(grid, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1' and !visited[i][j]) {
                    dfs(grid, i, j);
                    ++result;
                }
            }
        }
        return result;
    }
};
