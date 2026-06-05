class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);
        deque<int> st;
        int res = 0;
        for(string token : tokens){
            if(token == "+"){
                int tempres = 0;
                int cnt = 2;
                while(cnt > 0)
                {
                    tempres += st.back();
                    st.pop_back();
                    --cnt;
                } 
                res = tempres;
                cout << tempres << endl;
                st.push_back(tempres);
            } else if(token == "-"){
                int tempres = *(st.cend()-2);
                st.erase(st.cend()-2);
                int cnt = 1;
                while(cnt > 0)
                {
                    tempres -= st.back();
                    st.pop_back();
                    --cnt;
                } res = tempres;
                cout << tempres << endl;
                st.push_back(tempres);
            } else if(token == "*"){
                int tempres = 1;
                int cnt = 2;
                while(cnt > 0)
                {
                    tempres *= st.back();
                    st.pop_back();
                    --cnt;
                } res = tempres;
                cout << tempres << endl;
                st.push_back(tempres);
            } else if(token == "/"){
                int tempres = *(st.cend()-2);
                st.erase(st.cend()-2);
                int cnt = 1;
                while(cnt > 0)
                {
                    tempres /= st.back();
                    st.pop_back();
                    --cnt;
                } res = tempres;
                cout << tempres << endl;
                st.push_back(tempres);
            } else {
                st.push_back(stoi(token));
            }
        }
        return res;
    }
};
