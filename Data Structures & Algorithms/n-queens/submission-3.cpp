class Solution {
public:
    int numgrids;
    vector<vector<string>> results;
    bool isValid(vector<string> grid, int i, int j){
        for(int x = 0; x < grid.size(); ++x){
            if(grid[i][x] == 'Q') return false;
        }
        for(int y = 0; y < grid.size(); ++y){
            if(grid[y][j] == 'Q') return false;
        }
        int m = i, n = j;
        while(m < grid.size() and n < grid.size()){
            if(grid[m][n] == 'Q') return false;
            ++m;
            ++n;
        }
        m = i, n = j;
        while(m >= 0 and n >= 0){
            if(grid[m][n] == 'Q') return false;
            --m;
            --n;
        }
        while(m < grid.size() and n < grid.size()){
            if(grid[m][n] == 'Q') return false;
            ++m;
            --n;
        }
        m = i, n = j;
        while(m >= 0 and n >= 0){
            if(grid[m][n] == 'Q') return false;
            --m;
            ++n;
        }
        return true;
    }
    void backtrack(int n, vector<string>& grid, int i, int j, int numqueens){
        if(i == n) {
            results.push_back(grid);
            return;
        }
        if(i >= n or j >= n or i < 0 or j < 0) return;
        for(int z = 0; z < n; ++z){
            if(isValid(grid, i, z)){
                grid[i][z] = 'Q';
                ++numqueens;
                backtrack(n, grid, i+1, z, numqueens);
                cout<<numqueens<<endl;
                --numqueens;
                grid[i][z] = '.';
            } else continue;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        backtrack(n, grid, 0, 0, 0);
        return results;
    }
};
