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
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root==NULL || root==p || root==q)    return root;
        
        TreeNode *RL=LCA(root->left,p,q);
        TreeNode *RR=LCA(root->right,p,q);
        
        if(RL==NULL)    return RR;
        else if(RR==NULL)   return RL;
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
};