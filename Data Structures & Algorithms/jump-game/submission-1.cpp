class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        int tgt = nums.size()-1;
        for(int i = tgt-1; i >= 0; --i){
            if(i + nums[i] >= tgt){
                tgt = i;
            }
        }
        return tgt == 0 ? true : false;
    }
};
