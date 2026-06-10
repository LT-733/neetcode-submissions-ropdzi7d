class Solution {
public:
    vector<int> v;
    string encode(vector<string>& strs) {
        string out = "";
        for(string s : strs){
            v.push_back(s.size());
            out += s;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> results;
        int curpos = 0;
        for(int n : v){
            results.push_back(s.substr(curpos, n));
            curpos += n;
        }
        return results;
    }
};
