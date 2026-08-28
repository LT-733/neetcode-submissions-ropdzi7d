class Solution {
public:
    vector<vector<pair<bool, bool>>> canflow;
    void dfs(vector<vector<int>>& heights, int i, int j, int ref){
        // if(i < 0 or j < 0 or i >= heights.size() or j >= heights[0].size()) return;
        if(!ref) canflow[i][j].first = true;
        else canflow[i][j].second = true;
        // if(i == 0 or j == 0) canflow[i][j].first = true;
        // if(i == heights.size()-1 or j == heights[0].size()-1) canflow[i][j].second = true;
        if(i < heights.size()-1 and heights[i+1][j] >= heights[i][j] and (ref == 0 ? canflow[i+1][j].first == false : canflow[i+1][j].second == false)) {
            dfs(heights, i+1, j, ref);
            // if(flowthere.first == true) canflow[i][j].first = true;
            // if(flowthere.second == true) canflow[i][j].second = true;
        }
        if(j < heights[0].size()-1 and heights[i][j+1] >= heights[i][j] and (ref == 0 ? canflow[i][j+1].first == false : canflow[i][j+1].second == false)){
            dfs(heights, i, j+1, ref);
        }
        if(i > 0 and heights[i-1][j] >= heights[i][j] and (ref == 0 ? canflow[i-1][j].first == false : canflow[i-1][j].second == false)){
            dfs(heights, i-1, j, ref);
        }
        if(j > 0 and heights[i][j-1] >= heights[i][j] and (ref == 0 ? canflow[i][j-1].first == false : canflow[i][j-1].second == false)){
            dfs(heights, i, j-1, ref);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        canflow.resize(heights.size(), vector<pair<bool, bool>> (heights[0].size(), {false, false}));
        for(int i = 0; i < heights.size(); ++i){
            dfs(heights, i, 0, 0);
            dfs(heights, i, heights[0].size()-1, 1);
        }
        for(int j = 0; j < heights[0].size(); ++j){
            dfs(heights, 0, j, 0);
            dfs(heights, heights.size()-1, j, 1);
        }
        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); ++i){
            for(int j = 0; j < heights[0].size(); ++j){
                if(canflow[i][j].first and canflow[i][j].second) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
