class Solution {
public:
    bool checkValidString(string s) {
        stack<int> l;
        stack<int> ast;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') l.push(i);
            if(s[i] == '*') ast.push(i);
            if(s[i] == ')') {
                if(!l.empty()) l.pop();
                else if(!ast.empty()) ast.pop();
                else return false;
            }
        }
        while(!l.empty() and !ast.empty()){
            if(l.top() > ast.top()) return false;
            l.pop();
            ast.pop();
        }
        return l.empty();
    }
};
