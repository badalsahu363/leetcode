class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>&ans,
             int n,int m,int color,int delRow[],int delCol[],int init){
        ans[row][col] = color;
        for(int i = 0;i<4;i++){
            int nrow =  row + delRow[i];
            int ncol =  col + delCol[i];
            if(nrow < n && nrow >= 0  && ncol < m && ncol >= 0 
               && image[nrow][ncol] == init && ans[nrow][ncol] != color){
                dfs(nrow,ncol,image,ans,n,m,color,delRow,delCol,init);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        int delRow[] = { -1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        vector<vector<int>>ans = image;
        dfs(sr,sc,image,ans,n,m,color,delRow,delCol,init);
        return ans;
    }
};