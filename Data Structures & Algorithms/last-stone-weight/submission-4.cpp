class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxheap;
        for(int stone : stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            int w1 = maxheap.top();
            maxheap.pop();
            int w2 = maxheap.top();
            maxheap.pop();
            // cout<<w1<<" "<<w2<<"\n";
            int diff = abs(w1 - w2);
            // std::cout<<diff<<"\n";
            if(diff) maxheap.push(diff);
        }
        return maxheap.empty() ? 0 : maxheap.top();
    }
};
