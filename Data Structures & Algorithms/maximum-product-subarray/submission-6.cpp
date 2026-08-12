class Solution {
public:
    // vector<int> dp;
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums.back();
        int maxprod = nums[0], minprod = nums[0], overall = 0;
        for(int i = 1; i < nums.size(); ++i){
            int maxnow = maxprod * nums[i], minnow = minprod * nums[i];
            maxprod = max(max(maxnow, minnow), nums[i]);
            minprod = min(min(maxnow, minnow), nums[i]);
            overall = max(max(maxprod, minprod), overall);
        }
        return overall;
    }
};
