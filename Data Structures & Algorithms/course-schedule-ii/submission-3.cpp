class Solution {
public:
    vector<int> result;
    void dfs(vector<int>& needstaking, vector<vector<int>>& prerequisites, vector<vector<int>>& coursetrack, int i){
        result.push_back(i);
        --needstaking[i];
        for(int j : coursetrack[i]){
            --needstaking[j];
            if(!needstaking[j]) dfs(needstaking, prerequisites, coursetrack, j);
        }       
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // NEEDSTAKING ON EACH INDEX MEANS THIS COURSE LEADS TO SO MANY COURSES
        vector<int> needstaking(numCourses, 0);
        vector<vector<int>> coursetrack(numCourses);
        for(vector<int> req : prerequisites){
            needstaking[req[0]]++;
            coursetrack[req[1]].push_back(req[0]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!needstaking[i]) dfs(needstaking, prerequisites, coursetrack, i);
        }
        if(result.size() != numCourses) return {};
        return result;
        
    }
};
