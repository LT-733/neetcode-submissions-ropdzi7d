class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sp;
        for(int i = 0; i < speed.size(); ++i){
            sp.push_back({position[i], speed[i]});
        }
        sort(sp.rbegin(), sp.rend());
        stack<double> st;
        for(pair<int, int> s : sp){
            double eta = (double) (target - s.first) / s.second;
            if(st.empty() or st.top() < eta){
                st.push(eta);
            }
        }
        return st.size();
    }
};
