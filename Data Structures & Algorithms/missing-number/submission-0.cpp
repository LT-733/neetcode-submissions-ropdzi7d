class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int offset = 0;
        for(int i = 0; i <= nums.size(); ++i){
            offset = offset xor i;
        }
        for(int i : nums){
            offset = offset xor i;
        }
        return offset;
    }
};
