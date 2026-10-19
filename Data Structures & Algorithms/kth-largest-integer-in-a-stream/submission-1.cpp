class KthLargest {
public:
    int order;
    priority_queue<int, vector<int>, greater<int>> curnums;
    KthLargest(int k, vector<int>& nums) {
        order = k;
        curnums = priority_queue<int, vector<int>, greater<int>> (nums.begin(), nums.end());
    }
    
    int add(int val) {
        while(curnums.size() > order) curnums.pop();
        curnums.push(val);
        if(curnums.size() > order) curnums.pop();
        return curnums.top();
    }
};
