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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            //case 1: if curr ->left is null then store and go to right
            if(curr -> left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;
                //go to the right most part
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                //case 2: first check and then traverse: if prev->right is null then connect thread and then traverse left 
                if(prev->right == NULL){
                    prev->right = curr;
                    curr =  curr->left;
                }else{
                    //case 3: if prev->right is not null then cut the thread and store and go to the right part
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};