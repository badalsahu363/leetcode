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
    void rootToleaf(TreeNode*root,string currString,vector<string>&ans){
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL){
            //just add the path to the string
            currString += to_string(root->val);
            ans.push_back(currString);
            return;
        }
        
        string curr = to_string(root->val)+"->";
        if(root->left != NULL){
            rootToleaf(root->left,currString+curr,ans);
        }
        if(root->right != NULL){
             rootToleaf(root->right,currString+curr,ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        rootToleaf(root,"",ans);
        return ans;
    }
};