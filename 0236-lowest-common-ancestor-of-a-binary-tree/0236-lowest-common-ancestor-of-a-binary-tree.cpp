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
    
    TreeNode *lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root==p || root==q)   return root;
        
        TreeNode * l = lca(root->left,p,q);
        TreeNode * r = lca(root->right,p,q);
        
        if(!l) return r;
        else if(!r)  return l;
        else return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return root;
        return lca(root,p,q);
    }
};