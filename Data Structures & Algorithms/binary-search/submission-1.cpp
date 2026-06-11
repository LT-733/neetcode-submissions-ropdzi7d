class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] > target){
                cout << nums[mid] << endl;
                r = mid-1;
            } else if(nums[mid] < target){
                cout << nums[mid] << endl;
                l = mid+1;
            } else {
                cout << nums[mid] << endl;
                return mid;
            }
        }
        return -1;
    }
};
