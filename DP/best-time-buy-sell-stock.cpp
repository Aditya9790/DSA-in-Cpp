 int maxProfit(vector<int>& prices)
    {
        int maxprofit = 0, mini = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int cost = prices[i] - mini; // profit if sold at current day
            maxprofit = max(maxprofit, cost); // max profit
            mini = min(mini, prices[i]); // min cost encountered until i th index
            
            // minsofar = min(minsofar, prices[i]);
            // maxprofit = max(maxprofit, prices[i] - minsofar);
        }
        return maxprofit;
    }
