/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode *rec(TreeNode *root, TreeNode *tar){
        if(!root)   return NULL;
        
        if(root->val == tar->val)   return root;
        TreeNode *leftside = rec(root->left,tar);
        if(leftside)    return leftside;
        TreeNode *rightside = rec(root->right,tar);
        if(rightside)   return rightside;
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return rec(cloned,target);
    }
};