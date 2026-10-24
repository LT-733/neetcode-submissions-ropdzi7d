class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for(int i = 0; i < points.size(); ++i){
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.emplace(dist, i);
        }
        vector<vector<int>> res;
        for(int i = 0; i < k; ++i){
            const auto cur = pq.top();
            pq.pop();
            res.emplace_back(points[cur.second]);
        }
        return res;
    }
};
