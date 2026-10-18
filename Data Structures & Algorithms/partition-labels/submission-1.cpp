class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        // unordered_map<char, int> first;
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); ++i){
            {
                last[s[i]] = i;
            }
        }
        int end = 0, size = 0;
        for(int i = 0; i < s.size(); ++i){
            ++size;
            end = max(end, last[s[i]]);
            if(i == end){
                res.emplace_back(size);
                size = 0;
            }
        }
        return res;
    }
};
