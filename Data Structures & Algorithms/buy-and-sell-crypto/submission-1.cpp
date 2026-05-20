class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices.at(i) < buy) buy = prices.at(i);
            else{
                maxprofit = max(maxprofit, prices.at(i) - buy);
            }
        }
        return maxprofit;
    }
};
