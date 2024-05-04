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
    int rec(TreeNode *root){
        if(!root)   return INT_MAX;
        
        int diff=INT_MAX;
        if(root->left)  diff=min(diff,abs(root->val-root->left->val));
        if(root->right) diff=min(diff,abs(root->val-root->right->val));
        if(root->left && root->right)   diff=min(diff,abs(root->right->val-root->left->val));
        
        
        return min(diff,min(rec(root->left) , rec(root->right)));
    }
    
    void helper(TreeNode *root, int &pre, int &res) {
        if (root) {
            helper(root->left, pre, res);
            if (pre != -1) {
                res = min(res, root->val - pre);
            }
            pre = root->val;
            helper(root->right, pre, res);
        }
    }

    
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        helper(root, pre, res);
        return res;
    }
};