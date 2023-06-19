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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            size_t n = Q.size();
            double avg = 0.0;
            for(int i=0;i<n;i++){
                TreeNode* front = Q.front();
                avg+= front->val;
                Q.pop();
                if(front->left != NULL) Q.push(front->left);
                if(front->right != NULL) Q.push(front->right);
            }
            result.push_back(avg/(double)n);
        }
        return result;
    }
};