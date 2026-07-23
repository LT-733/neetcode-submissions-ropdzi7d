class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int, vector<int>, greater<int>> dists;
        vector<vector<int>> results;
        for(int i = 0; i < points.size(); ++i){
            auto point = points[i];
            dists.push(point[0]*point[0] + point[1]*point[1]);
        }
        int j = 0;
        while(j < k){
            // for(int i = 0; i < points.size(); ++i){
            //     cout<<points[i][0]<<" "<<points[i][1]<<endl;
            // }
            int cur = dists.top();
            int z = 0;
            for(; z < points.size(); ++z){
                auto point = points[z];
                // cout<<point[0]<<" "<<point[1]<<"\n";
                if(point[0]*point[0] + point[1]*point[1] == cur){
                    results.push_back(point);
                    break;
                }
            }
            vector<int>& point = points[z];
            // cout<<points.back()[0]<<" "<<points.back()[1]<<"\n";
            // cout<<point[0]<<" "<<point[1]<<"\n";
            swap(points.back(), point);
            // cout<<points.back()[0]<<" "<<points.back()[1]<<"\n";
            // cout<<point[0]<<" "<<point[1]<<"\n";
            points.pop_back();
            // cout<<points.back()[0]<<" "<<points.back()[1]<<"\n";
            dists.pop();
            ++j;
            // for(int i = 0; i < points.size(); ++i){
            //     cout<<points[i][0]<<" "<<points[i][1]<<endl;
            // }
        }
        return results;
    }
};
