class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};

        for (int n : nums){
            int size = result.size();
            for(int i = 0; i < size; ++i){
                vector<int> curres = result[i];
                curres.push_back(n);
                result.push_back(curres);
            }
        }
        return result;
    }
};
