class Solution {
public:
    bool isValid(string s){
        int i = 0, j = s.length()-1;
        while(j > i){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> res;
    void backtrack(vector<string>& part, int curidx, string s){
        if(curidx >= s.length()) {
            res.push_back(part);
            return;
        }
        for(int i = curidx; i < s.length(); ++i){
            if(isValid(s.substr(curidx, i-curidx+1))){
                part.push_back(s.substr(curidx, i-curidx+1));
                backtrack(part, i+1, s);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        backtrack(part, 0, s);
        return res;
    }
};
