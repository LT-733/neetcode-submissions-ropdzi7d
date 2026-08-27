class Solution {
    enum fruits{
        blank = 0,
        fresh = 1,
        rotten = 2
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int numfresh = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == fresh) ++numfresh;
            }
        }
        int cost = 0;
        while(numfresh > 0 and !q.empty()){
            int len = q.size();
            for(int x = 0; x < len; ++x)
            {int i = q.front().first, j = q.front().second;
            q.pop();
            // int used = 0;
            if(i+1 < grid.size() and grid[i+1][j] == fresh){
                grid[i+1][j] = rotten;
                --numfresh;
                q.push({i+1, j});
                // ++used;
            }
            if(i > 0 and grid[i-1][j] == fresh){
                cout<<grid[i-1][j]<<"\n";
                grid[i-1][j] = rotten;
                --numfresh;
                q.push({i-1, j});
                // ++used;
            }
            if(j+1 < grid[0].size() and grid[i][j+1] == fresh){
                grid[i][j+1] = rotten;
                --numfresh;
                q.push({i, j+1});
                // ++used;
            }
            if(j > 0 and grid[i][j-1] == fresh){
                grid[i][j-1] = rotten;
                --numfresh;
                q.push({i, j-1});
                // ++used;
            }}
            // if(used) 
            ++cost;
        }
        // for(int i = 0; i < grid.size(); ++i){
        //     for(int j = 0; j < grid[0].size(); ++j){
        //         if(grid[i][j] == 1){
        //             cout<<i<<" "<<j<<"\n";
        //             return -1;
        //         }
        //     }
        // }
        if(numfresh != 0) return -1;
        return cost;
    }
};
