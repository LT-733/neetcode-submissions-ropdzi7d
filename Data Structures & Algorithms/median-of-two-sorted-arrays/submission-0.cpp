class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int half = (total+1)/2;

        if(nums2.size() < nums1.size()){
            swap(nums2, nums1);
        }

        int l = 0;
        int r = nums1.size();
        while(l <= r){
            int i = (l+r)/2;
            int j = half - i;

            int n1l = i > 0 ? nums1[i-1] : INT_MIN;
            int n1r = i < nums1.size() ? nums1[i] : INT_MAX;
            int n2l = j > 0 ? nums2[j-1] : INT_MIN;
            int n2r = j < nums2.size()? nums2[j] : INT_MAX;

            if(n1l <= n2r and n2l <= n1r){
                if(total%2 != 0){
                    return max(n1l, n2l);
                }
                return (max(n1l, n2l) + min(n1r, n2r)) / 2.0;
            } else if(n1l > n2r){
                r = i-1;
            } else {
                l = i+1;
            }
        }
        return -1;
    }
};
