// class Solution {
// public:
    
    
//      int f(int ind,vector<int>&dp){
//         dp[0] = 1;
//         dp[1] = 1;
//          for(int i =2;i<=ind;i++){
//             dp[i] = dp[ind-1] + dp[ind-2];
//          }
         
//         return dp[ind];
//     }
    
    
    class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)   
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
    
