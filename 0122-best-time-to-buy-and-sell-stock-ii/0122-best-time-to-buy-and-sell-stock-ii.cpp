class Solution {
public:
    int f(int ind,int buy,vector<int>&prices, vector<vector<int>>&dp){
        int n = prices.size();
        if(ind == n) return 0;
        int profit = 0;    
         if(dp[ind][buy]!=-1)  return dp[ind][buy];
        if(buy){
            //max of take and not take
           profit = max(-prices[ind] + f(ind+1,0,prices,dp),0 +                                             f(ind+1,1,prices,dp));
        }else{
            //max of take and not take
            profit = max(prices[ind] + f(ind+1,1,prices,dp), 0 +                                        f(ind+1,0,prices,dp));
        }
        
        return dp[ind][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    int profit = 0;
    // 2 states: one is index and another is buy
    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                // max of take and not take
                profit = max(0+dp[ind+1][1], prices[ind] + dp[ind+1][0]);
            } else {
                // max of take and not take
                profit = max(0+dp[ind+1][0], -prices[ind] + dp[ind+1][1]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}
};
