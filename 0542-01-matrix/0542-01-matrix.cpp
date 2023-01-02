class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
	   int n = grid[0].size();
	   vector<vector<int>>vis(m,vector<int>(n,0));
	   vector<vector<int>>distance(m,vector<int>(n,0));
	   queue<pair<pair<int,int>,int>>q;
	   for(int i = 0;i<m;i++){
	       for(int j = 0;j<n;j++){
	           if(grid[i][j] == 0 ){
	               q.push({{i,j},0});
	               vis[i][j] = 1;
	           }else{
	               vis[i][j] = 0;
	           }
	       }
	   }
	   int delRow[] = {-1,0,+1,0};
	   int delCol[] = {0,+1,0,-1};
	   
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int steps = q.front().second;
	       q.pop();
	       distance[row][col] = steps;
	       
	       for(int i = 0;i<4;i++){
	           int nrow = delRow[i] + row;
	           int ncol = delCol[i] + col;
	           if(nrow < m &&  nrow >= 0 && ncol < n && ncol >= 0 
	           && vis[nrow][ncol] == 0){
	               vis[nrow][ncol] = 1;
	               q.push({{nrow,ncol},steps+1});
	           }
	       }
	   }
	   return distance;
	}
};

