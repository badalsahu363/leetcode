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
    private:
    void rootToleaf(TreeNode*root,string currString,int ans[]){
        if(root->left==NULL && root->right==NULL){
            //convert the binary to decimal and return
            currString += to_string(root->val);
            ans[0] += stoi(currString,0,2);
            return;
        }
        
        string curr = to_string(root->val);
        if(root->left != NULL){
            rootToleaf(root->left,currString+curr,ans);
        }
        if(root->right != NULL){
             rootToleaf(root->right,currString+curr,ans);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans[] = {0};
        ans[0] = 0;
        rootToleaf(root,"",ans);
        return ans[0];
    }
};