class Solution {
public:
    unordered_map<int, vector<int>> scan;
    unordered_set<int> track;
    bool dfs(int i){
        if(track.count(i)) return false;
        if(scan[i].empty()) return true;
        track.insert(i);
        for(int x : scan[i]){
            if(!dfs(x)) return false;
        }
        track.erase(i);
        scan[i].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; ++i){
            scan[i] = {};
        }
        for(vector<int> x : prerequisites){
            scan[x[0]].push_back(x[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i)) return false;
        }
        return true;
    }
};
