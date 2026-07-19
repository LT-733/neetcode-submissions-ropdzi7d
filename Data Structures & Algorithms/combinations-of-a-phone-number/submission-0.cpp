class Solution {
public:
    vector<string> characters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(vector<string>& results, const string digits, int curidx, string& now){
        if(curidx == digits.length()) {
            results.push_back(now);
            return;
        }
        cout<<characters[digits[curidx] - '0']<<endl;
        for(int i = 0; i < characters[digits[curidx] - '0'].size(); ++i){
            now += characters[digits[curidx] - '0'][i];
            backtrack(results, digits, curidx+1, now);
            now.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> results;
        string now = "";
        backtrack(results, digits, 0, now);
        return results;
    }
};
