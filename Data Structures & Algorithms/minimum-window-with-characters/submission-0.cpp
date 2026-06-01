class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        map<char, int> window;
        int l = 0, r = l;
        int cur = 0, resultLen = INT_MAX;
        map<char, int> expected;
        pair<int, int> result = {1, 1};
        for(char c : t){
            expected[c]++;
        }
        int numNeeded = expected.size();
        while(r < s.length()){
            window[s.at(r)]++;
            if(expected.contains(s.at(r)) && expected[s.at(r)] == window[s.at(r)]){
                ++cur;
            }
            while(numNeeded == cur){
                if((r-l+1) < resultLen){
                    result = {l, r};
                    resultLen = r-l+1;
                }

                window[s[l]]--;
                if(expected.contains(s.at(l)) && window[s.at(l)] < expected[s.at(l)]){
                    cur--;
                }
                ++l;
            }
            ++r;
        }

        return resultLen == INT_MAX ? "" : s.substr(result.first, resultLen);
    }
};
