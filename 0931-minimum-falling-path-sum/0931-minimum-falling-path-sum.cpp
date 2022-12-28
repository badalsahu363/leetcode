class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,int m,vector<vector<int>>&dp){
        // here we are starting from variable starting point so we need to handle the cases
        if(j < 0 || j >=m ) return 1e8;
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + f(i-1,j,matrix,m,dp);
        int ld = matrix[i][j] + f(i-1,j-1,matrix,m,dp);
        int rd = matrix[i][j] + f(i-1,j+1,matrix,m,dp);
        
        return dp[i][j] = min(up,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>>dp(n,vector<int>(n,0));
      for(int j = 0;j<m;j++) dp[0][j] = matrix[0][j];
      for(int i =1;i<n;i++){
          for(int j = 0;j<m;j++){
                int up =  matrix[i][j]+f(i-1,j,matrix,m,dp);
                int ld = matrix[i][j];
                if(j-1 >= 0) ld +=  dp[i-1][j-1];
                else ld+= 1e9;
                int rd = matrix[i][j];
                if(j+1 < m) rd+= dp[i-1][j+1];
                else rd+= 1e9;
                dp[i][j] = min(up,min(ld,rd));
          }
      }
      int mini = 1e9;
      for(int j = 0;j<m;j++){
          mini = min(mini,dp[n-1][j]);
      }  
      return  mini;
    }
};