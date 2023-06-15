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
    int solve(TreeNode* root, int& preVal, int& ans) {
        
        if(root->left) solve(root->left,preVal,ans);
        if(preVal >=0 ) ans = min(ans, abs(preVal - root->val));
        preVal = root->val;
        if(root->right) solve(root->right, preVal,ans);
      
        return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        int prevVal = -1;
        int ans = INT_MAX;
        return solve(root, prevVal ,ans);
    }
};