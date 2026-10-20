class KthLargest {
public:
    int k_th = 0;
    priority_queue<int> minheap;
    KthLargest(int k, vector<int>& nums) {
        for(int num : nums){
            minheap.push(num);
        }
        k_th = k;
    }
    
    int add(int val) {
        minheap.push(val);
        priority_queue<int> copy(minheap);
        // cout<<copy.top()<<"\n";
        for(int i = 0; i < k_th-1; ++i){
            copy.pop();
        }
        return copy.top();
    }
};
