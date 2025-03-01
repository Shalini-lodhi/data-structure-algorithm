class Solution {
public:
    /*
     prices = [
        0 | 7
        1 | 1  -> buy
        2 | 5
        3 | 3
        4 | 6 -> sell
        5 | 4
     ]
    */
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        // #1 -> 0 < days < 2
        if (days == 0 || days < 2)
            return 0;

        int maxProfit = 0, minPrice = prices[0];

        // #2 Iterating over the Days
        for (int i = 1; i < days; ++i) {
            // #2.1 If next day price < today's price
            if (prices[i] > prices[i - 1])
                maxProfit = max(maxProfit, (prices[i] - minPrice));
            // #2.2 if today's price < existing min-price
            else
                minPrice = min(minPrice, prices[i]);
        }
        // #3 return maxProfit
        return maxProfit;
    }
};