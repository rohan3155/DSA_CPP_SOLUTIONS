class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, best_buy = prices[0];
        int n = prices.size();
        for (int val : prices) {
            best_buy = min(best_buy, val);
            if (val > best_buy) {
                max_profit = max(max_profit, val - best_buy);
            }
        }

        return max_profit;
    }
};