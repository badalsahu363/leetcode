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
    vector<int>curr(2,0);
    vector<int>ahead(2,0);
    ahead[0] = ahead[1] = 0;
    int profit = 0;
    // 2 states: one is index and another is buy
    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                // max of take and not take
                profit = max(0+ahead[1], prices[ind] + ahead[0]);
            } else {
                // max of take and not take
                profit = max(0+ahead[0], -prices[ind] + ahead[1]);
            }
            curr[buy] = profit;
            
        }
         ahead = curr;
    }
    return curr[0];
}
};
