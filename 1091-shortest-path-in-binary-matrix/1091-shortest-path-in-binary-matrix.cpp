class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int, int> source={0,0};
        pair<int, int> destination={n-1,n-1};
        if(grid[source.first][source.second]==1){
            return -1;
        }
        if(source.first==destination.first && source.second==destination.second){
            return 1;
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[source.first][source.second]=0;
        q.push({1,{source.first,source.second}});
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && distance+1<dist[nr][nc]){
                    dist[nr][nc]=distance+1;
                    if(nr==destination.first && nc==destination.second){
                        return distance+1;
                    }
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};