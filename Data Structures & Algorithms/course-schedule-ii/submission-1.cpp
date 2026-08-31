class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // NEEDSTAKING ON EACH INDEX MEANS THIS COURSE LEADS TO SO MANY COURSES
        vector<int> needstaking(numCourses, 0);
        vector<vector<int>> coursetrack(numCourses);
        for(vector<int> req : prerequisites){
            needstaking[req[1]]++;
            coursetrack[req[0]].push_back(req[1]);
        }
        queue<int> noreqs;
        vector<int> res;
        for(int i = 0; i < numCourses; ++i){
            if(needstaking[i] == 0) {
                res.push_back(i);
                noreqs.push(i);
            }
        }
        while(!noreqs.empty()){
            int cur = noreqs.front();
            noreqs.pop();
            for(int c : coursetrack[cur]){
                --needstaking[c];
                if(!needstaking[c]){
                    noreqs.push(c);
                    res.push_back(c);
                }
            }
        }
        reverse(res.begin(), res.end());
        if(res.size() < numCourses) return {};
        return res;
    }
};
