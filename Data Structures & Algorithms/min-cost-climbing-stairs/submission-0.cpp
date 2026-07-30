class Solution {
public:
    int price = 0;
    unordered_map<int, int> solutions;
    int minCostClimbingStairs(vector<int>& cost, int idx){
        int result = 0;
        if(solutions.find(idx) != solutions.end()) return solutions[idx];
        else{
            if(solutions.find(idx-1) == solutions.end()) solutions[idx-1] = minCostClimbingStairs(cost, idx-1);
            if(solutions.find(idx-2) == solutions.end()) solutions[idx-2] = minCostClimbingStairs(cost, idx-2);
            result = min(solutions[idx-1] + cost[idx-1], solutions[idx-2] + cost[idx-2]);
        }
        return result;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        solutions[0] = 0;
        solutions[1] = 0;
        return minCostClimbingStairs(cost, cost.size());
    }
};