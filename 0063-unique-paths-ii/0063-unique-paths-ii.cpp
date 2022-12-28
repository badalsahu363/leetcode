class Solution {
public:
     int f(int i,int j,vector<vector<int>>&obstracleGrid,vector<vector<int>>&dp){
        
        if(i >= 0 && j >= 0 && obstracleGrid[i][j] == 1) return 0;
        
        if(i == 0 && j==0) return 1;
        
        if(i<0 || j<0) return 0;
        
         if(dp[i][j] != -1) return dp[i][j];
         
        int up = f(i-1,j,obstracleGrid,dp);
        int left = f(i,j-1,obstracleGrid,dp);
        
        return dp[i][j] =  (up + left);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       vector<vector<int>>dp(m,vector<int>(n+1,-1));
       return f(m-1,n-1,obstacleGrid,dp); 
    }
};