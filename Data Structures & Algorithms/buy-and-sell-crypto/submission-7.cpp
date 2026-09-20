using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            prices = [10,1,5,6,7,1]
        */

        int min_buy_price = prices[0];
        int max_profit = 0;

        int i;
        for (i = 1; i < prices.size(); i++) {
            int current_price = prices[i];

            if (min_buy_price > current_price) {
                min_buy_price = current_price;
            } else {
                int current_profit = current_price - min_buy_price;
                max_profit = max(max_profit, current_profit);
            }
        }

        return max_profit;
    }
};
