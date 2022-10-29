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
    TreeNode* solve(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map< int, int> &inmap)
        {
           	//base case
            if (postStart > postEnd || inStart > inEnd)
                return NULL;
            TreeNode *root = new TreeNode(postorder[postEnd]);
            int in = inmap[root->val];
            int left = in -inStart;
            root->left = solve(postorder, postStart,postStart+left-1, inorder, inStart, in -1, inmap);
            root->right = solve(postorder, postStart+left,postEnd-1, inorder, in +1, inEnd, inmap);
            return root;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        return solve(postorder,0,postorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }
};