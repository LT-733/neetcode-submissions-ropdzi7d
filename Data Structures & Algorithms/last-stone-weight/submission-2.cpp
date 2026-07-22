class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> mystones(stones.begin(), stones.end());
        while (!mystones.empty()){
            int curstone = mystones.top();
            mystones.pop();
            cout<<curstone<<endl;
            if(mystones.empty()){
                return curstone;
            }
            int nextstone = mystones.top();
            mystones.pop();
            cout<<nextstone<<endl;
            int newlyAdded = abs(curstone - nextstone);
            if(newlyAdded) mystones.push(newlyAdded);
            if(mystones.empty()) mystones.push(newlyAdded);
        }
        return mystones.top();
    }
};
