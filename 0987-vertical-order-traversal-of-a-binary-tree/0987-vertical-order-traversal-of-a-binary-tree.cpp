class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes; // vertical,level,multinodes
        queue<pair<TreeNode*,pair<int,int>>>level; // level order traversal 
        level.push({root,{0,0}});
        while(!level.empty()){
            auto it = level.front();
            level.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(node->left != NULL) level.push({node->left,{x-1,y+1}});
            if(node->right != NULL) level.push({node->right,{x+1,y+1}});
            nodes[x][y].insert(node->val);
        }
            vector<vector<int>>ans;
            for(auto p : nodes){
                vector<int>col;
                for(auto q : p.second){
                    col.insert(col.end(),q.second.begin(),q.second.end());
                }
                 ans.push_back(col);
            }
            return ans;
        }
};