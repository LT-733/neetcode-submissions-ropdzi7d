class Solution {
public:
    vector<string> results;
    // bool isproper(string s){
    //     stack<char> st;
    //     for(char c : s){
    //         // cout<<c<<endl;
    //         if(c == '(') st.push(c);
    //         if(c == ')' and !st.empty()) st.pop();
    //         else if(c == ')' and st.empty()) return false;
    //     }
    //     return st.empty();
    // }
    void backtrack(int n, string str, int& open, int& closed){
        cout<<str<<endl;
        if(closed == open and closed == n) {results.push_back(str); return;}
        if(open < n) {
            str += "(";
            ++open;    
            backtrack(n, str, open, closed);
            str.pop_back();
            --open;
        }

        if(closed < open){
            str += ")";
            ++closed;
            backtrack(n, str, open, closed);
            str.pop_back();
            --closed;
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int l = 0, r = 0;
        backtrack(n, s, l, r);
        return results;
    }
};
