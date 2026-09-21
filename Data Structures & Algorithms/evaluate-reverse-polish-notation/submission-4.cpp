class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string token : tokens){
            if(token != "+" and token != "-" and token != "*" and token != "/"){
                st.push(token);
            }
            else{
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(token == "+"){
                    st.push(to_string(a+b));
                }
                if(token == "-"){
                    st.push(to_string(b-a));
                }
                if(token == "*"){
                    st.push(to_string(b*a));
                }
                if(token == "/"){
                    st.push(to_string(b/a));
                }
            }
        }
        return stoi(st.top());
    }
};
