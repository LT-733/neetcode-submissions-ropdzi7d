class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(nums.at(l) <= nums.at(r)){
            while(l <= r){
                int mid = (l+r)/2;
                if(nums[mid] < target) l = mid+1;
                else if(nums[mid] > target) r = mid-1;
                else return mid;
            }
        }
        // idea: find the target by spotting whether our bounds compare
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(nums[l] <= nums[mid] and target >= nums[l] and target < nums[mid]){
                r = mid-1;
            }else if(nums[mid] <= nums[r] and target <= nums[r] and target > nums[mid]){
                l = mid+1;
            }else if(nums[l] <= nums[mid] and target < nums[l]){
                l = mid+1;
            }else if(nums[r] >= nums[mid] and target > nums[r]){
                r = mid-1;
            }else if(nums[mid] <= nums[r] and target < nums[mid]){
                r = mid-1;
            }else if(nums[mid] >= nums[l] and target > nums[mid]){
                l = mid+1;
            }
        }
        return -1;
    }
};
