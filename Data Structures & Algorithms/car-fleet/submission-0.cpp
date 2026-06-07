class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < position.size(); ++i){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<double> st;
        for(pair<int, int> p : pairs){
            double d = (double)(target - p.first) / p.second;
            if(st.empty() || d > st.top()) {
                st.push(d);
            }
        }
        return st.size();
    }
};
