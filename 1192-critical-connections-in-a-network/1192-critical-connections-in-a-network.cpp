class Solution {
private:
    //declaring globally
    int timer = 1;
private:
    void dfs(int node,int parent,vector<int>&vis,int tim[],int low[],
             vector<vector<int>>&bridges,vector<int>adj[]){
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        //go across the adj nodes
        for(auto it : adj[node]){
            if(it == parent) continue;
            //if its not visited juust go and traverse
           
            if(vis[it] == 0){
                dfs(it,node,vis,tim,low,bridges,adj);
                 //after returning from the it 
                //whats your lowest time givve it to me
                low[node] = min(low[node],low[it]);
                //cant this node to it be the bridge
                // hey adjecent node what is your lowest time
                //my lowest time is low of it
                //if my lowest is greater than time of insertion
                //then there is a bridge between them 
                if(low[it] > tim[node]){
                    bridges.push_back({it,node});
                }
            }else{
                low[node] = min(low[node],low[it]);
            }
        }
       
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int tim[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,tim,low,bridges,adj);
        return bridges;
    }
}; 