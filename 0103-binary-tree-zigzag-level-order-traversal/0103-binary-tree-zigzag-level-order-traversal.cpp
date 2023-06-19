/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        queue<TreeNode*>q;
        bool LeftToRight= true; // left -> right
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()){
            
            int n = q.size();
            vector<int>level(n);
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                int index = (LeftToRight)?i:(n-1-i);
                level[index] = front->val;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
             
              LeftToRight = !LeftToRight;
               ans.push_back(level);
        }
        return ans;
    }
};