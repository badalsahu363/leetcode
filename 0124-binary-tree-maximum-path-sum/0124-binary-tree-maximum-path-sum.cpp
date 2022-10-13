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
    int findMaxPath(TreeNode*root,int &maxi){
        if(root == NULL) return 0;
        int maxLeftPath = max(0,findMaxPath(root->left,maxi));
        int maxRightPath = max(0,findMaxPath(root->right,maxi));
        //if root is my curving point
        maxi = max(maxi,maxLeftPath+maxRightPath+root->val);
        //if root is not my curving point
        return max(maxLeftPath,maxRightPath)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN;
       findMaxPath(root,maxi);
       return  maxi; 
    }
};