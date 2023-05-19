class Solution {
public: 
    int f(TreeNode* root){
        if(root == NULL) return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        
        if(abs(lh-rh) > 1) return -1;
        if(lh == -1 || rh == -1) return -1;
        return 1 + max(lh , rh);
    }
    bool isBalanced(TreeNode* root) {
        int ans = f(root);
        if(ans == -1) return false;
        return true;
    }
};