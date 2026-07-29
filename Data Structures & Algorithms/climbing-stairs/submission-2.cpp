class Solution {
public:
    unordered_map<int, int> solutions = {{1, 1}, {2, 2}};
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(solutions.find(n) != solutions.end()) return solutions[n];
        if(solutions.find(n-1) == solutions.end()) solutions[n-1] = climbStairs(n-1); 
        if(solutions.find(n-2) == solutions.end()) solutions[n-2] = climbStairs(n-2);
        solutions[n] = solutions[n-1] + solutions[n-2];
        return solutions[n];
    }
};
