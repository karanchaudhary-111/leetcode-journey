class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;

        for(auto& it: prices){
            mini = min(mini, it);
            profit = max(profit, it - mini);
        }

        return profit;
    }
};