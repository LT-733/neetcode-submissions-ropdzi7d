class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> tgt;
        for(const auto& t : triplets){
            if(t[0] > target[0] or t[1] > target[1] or t[2] > target[2]) continue;
            for(int i = 0; i < 3; ++i){
                if(t[i] == target[i]) tgt.insert(i);
            }
        }
        return tgt.size() == 3;
    }
};
