class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        if (!minheap.empty() && maxheap.top() > minheap.top()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() > maxheap.size()) return minheap.top();
        if(maxheap.size() > minheap.size()) return maxheap.top();
        return static_cast<double>(minheap.top() + maxheap.top())/2;
    }
};
