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
   vector<int> rightSideView(TreeNode *root)
        {
            vector<int> ans;
            if (root == NULL)
                return ans;
            queue<pair<TreeNode *, int>> level;
            map<int, int> top;
            level.push({ root,
                0 });
            while (!level.empty())
            {
                auto it = level.front();
                level.pop();
                TreeNode *node = it.first;
                int row = it.second;
                top[row] = node->val;
                if (node->left != NULL)
                    level.push({ node->left,
                        row + 1 });
                if (node->right != NULL)
                    level.push({ node->right,
                        row + 1 });
            }
            for (auto it: top)
            {
                ans.push_back(it.second);
            }
            return ans;
        }
};