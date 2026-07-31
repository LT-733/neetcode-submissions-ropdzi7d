class Solution {
public:
    int hunt(vector<int>& nums) {
        int hunt1 = 0, hunt2 = 0;
        for(int num : nums){
            int temp = max(hunt1 + num, hunt2);
            hunt1 = hunt2; 
            hunt2 = temp;
        }
        return hunt2;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums.back();
        vector<int> numsleft(nums.begin(), nums.begin() + nums.size()-1);
        vector<int> numsright(nums.begin()+1, nums.end());
        int resleft = hunt(numsleft);
        int resright = hunt(numsright);
        return max(resleft, resright);
    }
};
