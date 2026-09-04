class Solution {
public:
    int res = INT_MAX;
    int timeslen;
    void dfs(int cur, vector<vector<pair<int, int>>> neighbors, vector<int>& visited, int curres){
        if(visited[cur] <= curres) return;
        visited[cur] = curres;
        // if(visited.size() == timeslen) res = min(curres, res);
        for(auto p : neighbors[cur]){
            dfs(p.first, neighbors, visited, curres + p.second);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neighbors(n+1, vector<pair<int, int>>());
        for(auto time : times){
            neighbors[time[0]].push_back({time[1], time[2]});
        }
        vector<int> visited(n+1, INT_MAX);
        timeslen = n;
        dfs(k, neighbors, visited, 0);
        for(int i = 1; i < visited.size(); ++i){
            if(visited[i] == INT_MAX) return -1;
        }
        return *max_element(visited.begin()+1, visited.end());
    }
};
