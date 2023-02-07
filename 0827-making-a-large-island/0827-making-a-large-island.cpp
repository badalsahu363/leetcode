class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool  isValid(int row,int col,int n){
        return row>=0 && row < n && col >=0 && col <n;
    }
public:
    int largestIsland(vector<vector<int>>& matrix) {
        int n = matrix.size();
        DisjointSet ds(n*n);
        //step 1 : iterate over the matrix and find 1  and then traverse i n 4 directions
        for(int row =0;row < n;row++){
            for(int col =0;col<n;col++){
                if(matrix[row][col] == 0) continue;
                int delRow[] = {-1,0,1,0};
                int delCol[] = {0,-1,0,1};
                for(int ind = 0;ind <4;ind++){
                    int nrow = row  + delRow[ind];
                    int ncol = col + delCol[ind];
                    if(isValid(nrow,ncol,n) && matrix[nrow][ncol] == 1){
                        int nodeNo = row * n + col;
                        int adjNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo,adjNo);
                    }
                }
            }
        }
        int ans = 0;
        for(int row =0;row <n;row++){
             for(int col =0;col<n;col++){
                if(matrix[row][col] == 1) continue;
                int delRow[] = {-1,0,1,0};
                int delCol[] = {0,-1,0,1};
                 set<int>storeUparent;
                for(int ind = 0;ind <4;ind++){
                    int nrow = row  + delRow[ind];
                    int ncol = col + delCol[ind];
                    if(isValid(nrow,ncol,n)){
                        if(matrix[nrow][ncol] == 1){
                            storeUparent.insert(ds.findUPar(nrow*n+ncol));
                        }
                    }
                } 
                 int totalSum =0;
                for(auto it : storeUparent){
                    totalSum += ds.size[it];
                } 
                 ans = max(totalSum+1,ans);
             }
        }
        
        for(int cell = 0;cell < n*n;cell++){
            ans  = max(ds.size[ds.findUPar(cell)],ans);
        }
        return ans;
    }
};