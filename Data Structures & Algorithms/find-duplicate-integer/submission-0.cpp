class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for(int num : nums){
            if(seen.find(num) != seen.end()) return num;
            seen.insert(num);
        }
        return -1;
    }
};
