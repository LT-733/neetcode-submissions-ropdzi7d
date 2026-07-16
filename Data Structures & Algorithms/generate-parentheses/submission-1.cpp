class Solution {
public:
    vector<string> results;
    bool isproper(string s){
        stack<char> st;
        for(char c : s){
            // cout<<c<<endl;
            if(c == '(') st.push(c);
            if(c == ')' and !st.empty()) st.pop();
            else if(c == ')' and st.empty()) return false;
        }
        return st.empty();
    }
    void backtrack(int n, string str){
        // cout<<str<<endl;
        if(str.size() == n*2 and isproper(str)) {results.push_back(str); return;}
        if(str.size() > n*2) return;
        // if(str.back() == "(" and str.size() < n*2 - 2){
        //     str += "(";
        //     backtrack(n, str);
        //     str.pop_back();
        //     str += ")";
        //     backtrack(n, str);
        // }
        str += "(";
        backtrack(n, str);
        str.pop_back();
        str += ")";
        backtrack(n, str);
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        backtrack(n, s);
        return results;
    }
};
