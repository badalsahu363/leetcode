class Solution {
public:
    int countNodes(TreeNode* root) {
     if(root == NULL) return 0;
        int lh = leftHeightCount(root);
        int rh = rightHeightCount(root);
        if(lh == rh) (1<<lh)-1;
         return 1+ countNodes(root->left) + countNodes(root->right); 
    }
    
    int leftHeightCount(TreeNode*root){
        int cnt = 0;
        while(root!= NULL){
             cnt++;
            root = root->left;
           
        }
        return cnt;
    }
    
    
    int rightHeightCount(TreeNode*root){
        int cnt = 0;
        while(root!= NULL){
             cnt++;
            root = root->right;
           
        }
        return cnt;
    }
    
    
};