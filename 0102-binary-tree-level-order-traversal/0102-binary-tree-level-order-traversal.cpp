class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
                level.push_back(front->val);
            }
             ans.push_back(level);
        }
        return ans;
    }
};