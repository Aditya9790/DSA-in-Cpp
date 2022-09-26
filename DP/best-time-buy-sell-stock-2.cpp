/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Explaination : 

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

*/



class Solution
{
public:
    int maxp(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0; // if we bought a stock and didnt sell it then profit 0

        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;

        if (buy) // if bought a stock
        {
            int buy = -prices[ind] + maxp(ind + 1, 0, prices, dp); // buy stock (-) denotes we will loose money when we buy a stock

            int not_buy = 0 + maxp(ind + 1, 1, prices, dp);

            profit = max(buy, not_buy);
        }

        else // if sold a stock
        {
            int sold = prices[ind] + maxp(ind + 1, 1, prices, dp); // when we sell money will add up
            int not_sold = 0 + maxp(ind + 1, 0, prices, dp);

            profit = max(sold, not_sold);
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxp(0, 1, prices, dp);
    }
};

/*
Brute Force

 int maxp(int ind, int buy, vector<int>& prices)
    {
        if(ind==prices.size()) return 0; // if we bought a stock and didnt sell it then profit 0

        int profit = 0;

        if(buy) // if bought a stock
        {
            int buy = -prices[ind]+ maxp(ind+1, 0, prices); // buy stock (-) denotes we will loose money when we buy a stock

            int not_buy = 0 + maxp(ind+1, 1, prices);

            profit = max(buy, not_buy);
        }

        else // if sold a stock
        {
            int sold = prices[ind] + maxp(ind+1, 1, prices); // when we sell money will add up
            int not_sold = 0 + maxp(ind+1, 0, prices);

            profit = max(sold, not_sold);
        }

        return profit;
    }

*/
