#define ll long long
ll mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto &i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        
        
        vector<ll> timevec(n,1e18);
        vector<ll> ways(n,0);
        timevec[0]=0;
        ways[0]=1;
		priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,0}); // distance , node
        
        while(!pq.empty()){
            ll time = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            for(auto i:adj[node]){
                ll adjNode = i.first;
                ll weight = i.second;
                
                if(time+weight<timevec[adjNode]){
                    timevec[adjNode]=time+weight;
                    pq.push({timevec[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if((time+weight)<=timevec[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};
