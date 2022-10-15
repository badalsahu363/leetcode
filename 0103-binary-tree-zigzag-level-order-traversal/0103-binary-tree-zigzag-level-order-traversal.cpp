/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            vector<vector < int>> ans;
            if (root == NULL) return ans;
            queue<TreeNode*> q;
            q.push(root);
            bool leftToRight=true;
            while (!q.empty())
            {
                int size = q.size();
                vector<int> level(size);
                for (int i = 0; i < size; i++)
                {
                    TreeNode *front = q.front();
                    q.pop();
                    //find the position to insert
                    int index=(leftToRight)?i:(size-1-i);
                    if (front->left != NULL) q.push(front->left);
                    if (front->right != NULL) q.push(front->right);
                    level[index]=front->val;
                }
                leftToRight=!leftToRight;
                ans.push_back(level);
            }

            return ans;
        }
};