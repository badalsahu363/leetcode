class Solution
{
    public:
        void track_parent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                {
                    parent_track[front->left] = front;
                    q.push(front->left);
                }
                if (front->right)
                {
                    parent_track[front->right] = front;
                    q.push(front->right);
                }
            }
        }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        track_parent(root, parent_track);
        queue<TreeNode*> q;

        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (dist++ == k) break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (parent_track[front] && !visited[parent_track[front]])
                {
                    q.push(parent_track[front]);
                    visited[parent_track[front]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};