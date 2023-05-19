class Solution {
public:
    bool f(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && targetSum-root->val == 0) return true;
        
        
        return f(root->left,targetSum - root->val) || f(root->right,targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return f(root,targetSum);
    }
};

