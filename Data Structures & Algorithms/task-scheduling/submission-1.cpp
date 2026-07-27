class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto task : tasks){
            freq[task - 'A']++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 26; ++i){
            if(freq[i]) pq.push(freq[i]);
        }
        queue<pair<int, int>> wait;
        int result = 0;
        while(!pq.empty() or !wait.empty()){
            ++result;
            if(pq.empty()) result = wait.front().second;
            else{
                auto cur = pq.top();
                if (cur == 1){
                    pq.pop();
                } else{
                    pq.pop();
                    wait.push(make_pair(cur-1, result + n));
                }
            }
            if(!wait.empty() and wait.front().second == result){
                pq.push(wait.front().first);
                wait.pop();
            }
        }
        return result;
    }
};
