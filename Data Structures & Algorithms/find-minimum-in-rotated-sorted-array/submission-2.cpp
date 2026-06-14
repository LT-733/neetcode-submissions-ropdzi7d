class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;
        while(l <= r){
            if(nums[l] < nums[r]) ans = min(nums[l], ans);
            int mid = (l+r)/2;
            ans = min(ans, nums[mid]);
            // cout<<mid<<endl;
            // cout<<ans<<endl;
            if(nums[mid] <= nums[r]){
                // cout<<"adfas"<<endl;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
};
