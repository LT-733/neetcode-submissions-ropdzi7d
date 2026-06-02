class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()%2 != 0) return false;
        for(char c : s){
            if(c != ')' && c != '}' && c != ']'){
                st.push(c);
            } else{
                // cout<<st.top()<<endl;
                // cout<<c;
                if(st.empty()) return false;
                if(c == ')' && st.top() == '('){
                    st.pop();
                }
                else if(c == ']' && st.top() == '['){
                    st.pop();
                    // cout<<"used"<<endl;
                }
                else if(c == '}' && st.top() == '{'){
                    st.pop();
                } else {
                    // cout<<"gotcha!"<<endl;
                    return false;
                }
            }
        }
        return st.empty();
    }
};
