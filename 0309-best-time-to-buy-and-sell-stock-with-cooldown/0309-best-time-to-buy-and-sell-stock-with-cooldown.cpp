class Solution {
public:
    /*
    prices = [
        0 | 1, -> buy
        1 | 2, -> sell (p = 1)
        2 | 3, -> cooldown
        3 | 0, -> buy
        4 | 2  -> sell (p = 2)
        ]

    #1 -> hold[i] = max(hold[i-1], rest[i-1] - prices[i])
        Either we keep holding (same as hold[i-1]).
        Or we buy today (we must be in rest[i-1] state before buying).
    #2 -> sold[i] = hold[i-1] + prices[i]
        We sell the stock today, so our profit is yesterday's hold + today's price.
    
    #3 -> rest[i] = max(rest[i-1], sold[i-1])
        We either stay in rest (same as rest[i-1]).
        Or we enter rest because yesterday we sold (so we take sold[i-1]).

    Base Cases
        hold[0] = -prices[0] (If we buy on day 0, profit is -prices[0]).
        sold[0] = 0 (If we sell on day 0, it's not possible, so profit is 0).
        rest[0] = 0 (If we do nothing on day 0, profit is 0).
    */
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int n = prices.size();
        vector<int> hold(n, 0), sold(n, 0), rest(n, 0);

        hold[0] = -prices[0]; // Buying on day 0

        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
            sold[i] = hold[i - 1] + prices[i];
            rest[i] = max(rest[i - 1], sold[i - 1]);
        }

        // Max profit is when we are either resting or just sold
        return max(sold[n - 1], rest[n - 1]); // We cannot hold on the last day
    }
};
