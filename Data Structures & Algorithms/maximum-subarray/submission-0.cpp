class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestsum = INT_MIN;
        int cursum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(cursum + nums[i] < nums[i]) cursum = nums[i];
            else cursum += nums[i];
            // cout<<cursum<<"\n";
            if(cursum > bestsum) bestsum = cursum;
        }
        return bestsum;
    }
};
