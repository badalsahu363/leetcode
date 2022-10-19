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
    bool f(TreeNode* rootl,TreeNode* rootr){
      if(rootl == NULL || rootr == NULL) return (rootl==rootr);
      return (rootl->val == rootr->val)&&
        f(rootl->left,rootr->right) &&
        f(rootl->right,rootr->left);
        
       
    }
    bool isSymmetric(TreeNode* root) {
      return f(root->left,root->right);
    }
};