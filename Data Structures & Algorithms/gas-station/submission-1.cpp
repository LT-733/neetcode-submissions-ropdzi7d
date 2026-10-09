class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (reduce(gas.begin(), gas.end()) < reduce(cost.begin(), cost.end())) return -1;

        int res = 0, total = 0, i = 0;
        bool start = true;
        while(true){
            if(i >= gas.size()) i = 0;
            total += (gas[i] - cost[i]);
            if(i == res and total >= 0 and !start) break;
            if(start) start = false;
            if (total < 0){
                total = 0;
                res = i+1;
                start = true;
            }
            ++i;
        }
        return res;
    }
};
