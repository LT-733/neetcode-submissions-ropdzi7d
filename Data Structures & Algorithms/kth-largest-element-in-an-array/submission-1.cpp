class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mynums;
        for(int n : nums){
            mynums.push(n);
            if(mynums.size() > k) mynums.pop();
        }
        if(!mynums.empty()) return mynums.top();
    }
};
