class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1, k = nums.size()-1, target = -nums[i];
            // cout<<j<< " " << k <<endl;
            // cout<<nums.size()<<endl;
            // cout<<i<<endl;
            // cout<<nums[i]<<endl;
            while(j < k){
                // cout<<nums.at(k)<<" "<<nums.at(j)<<" "<<nums.at(k)+nums.at(j)<<endl;
                if(nums.at(k)+nums.at(j) < target){
                    // cout<<"got it"<<endl;
                    ++j;
                }else if (nums.at(k)+nums.at(j) > target){
                    --k;
                }else{
                    // cout<<"pushed"<<endl;
                    results.push_back({nums.at(i), nums.at(j), nums.at(k)});
                    ++j;
                    --k;
                    // while (j < k && nums[j] == nums[j - 1]) {
                    //     j++;
                    // }
                }
            }
            if(j == k) continue;
            // results.push_back({nums.at(i), nums.at(j), nums.at(k)});
        }
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        return results;
    }
};
