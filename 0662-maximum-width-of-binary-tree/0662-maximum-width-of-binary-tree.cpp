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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int ans = 0;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int first,last;
            int minindex = q.front().second;
            for(int i=0;i<size;i++){
                int curr_ind = q.front().second-minindex;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = curr_ind;
                if(i == size-1) last = curr_ind;
                if(node->left != NULL) q.push({node->left,(long long)2*curr_ind+1});
                if(node->right != NULL) q.push({node->right,(long long)2*curr_ind+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};