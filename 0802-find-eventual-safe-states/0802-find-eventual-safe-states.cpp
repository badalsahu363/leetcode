class Solution {
    private:
    bool dfsCheck(int node,vector<vector<int>>& graph,vector<int> &vis,
                  vector<int> &pathVis)
    {
        vis[node] =1;
        pathVis[node] =1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,graph,vis,pathVis) == true) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int vertices = graph.size();
	vector<int> vis(vertices,0);
	vector<int> pathVis(vertices,0);
        vector<int>safeNodes;
        for(int i=0;i<vertices;i++){
            if(!vis[i]){
                dfsCheck(i,graph,vis,pathVis);
            }
        }
        for(int i=0;i<vertices;i++){
            if(pathVis[i]==0) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};