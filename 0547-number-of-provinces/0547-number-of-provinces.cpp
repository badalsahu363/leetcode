class Solution
{
    public:
        void dfs(int node, vector<int> &vis, vector<int> adjLi[])
        {
            vis[node] = 1;

            for (auto it: adjLi[node])
            {
                if (!vis[it])
                {

                    dfs(it, vis, adjLi);
                }
            }
        }

    int findCircleNum(vector<vector < int>> &adj)
    {
        int V = adj.size();
        vector<int> adjLi[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLi[i].push_back(j);
                    adjLi[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, vis, adjLi);
            }
        }
        return cnt;
    }
};