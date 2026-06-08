class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carbatches;
        for(int i = 0; i < position.size(); ++i){
            carbatches.push_back({position[i], speed[i]});
        }
        stack<double> st;
        sort(carbatches.rbegin(), carbatches.rend());
        for(auto c : carbatches){
            double t = (double) (target - c.first) / c.second;
            if(st.empty() || t > st.top()){
                st.push(t);
            }
        }
        return st.size();
    }
};
