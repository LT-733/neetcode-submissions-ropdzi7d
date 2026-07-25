class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        int result = 0;
        priority_queue<int> pq;
        for(auto f : freq){
            if(f > 0) pq.push(f);
        }

        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()){
            ++result;
            if(pq.empty()) result = q.front().second;
            else{
                int cur = pq.top()-1;
                pq.pop();
                if(cur) q.push({cur, result+n});
            }

            if(!q.empty() and q.front().second == result){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return result;
    }
};
