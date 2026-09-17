class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i){
            int cur = 0;
            for(int j = 0; j < 32; ++j){
                if(1 << j & i){
                    ++cur;
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
