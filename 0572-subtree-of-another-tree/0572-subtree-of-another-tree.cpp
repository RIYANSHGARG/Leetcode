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
    bool isSameTree(TreeNode *root1, TreeNode *root2){
        if(!root1)  return (root1==root2);
        if((!root1 && root2) || (root1 && !root2))  return false;
        if(root1->val!=root2->val)   return false;
        return (isSameTree(root1->left,root2->left)&& isSameTree(root1->right,root2->right));
    }
    bool helper(TreeNode *root, TreeNode *subtree){
        if(!root)   return (root==subtree);
        
        if(root->val==subtree->val){
            if(isSameTree(root,subtree))    return true;
        }
        bool l=false,r=false;
        if(root->left)  l=helper(root->left,subtree);
        if(root->right)  r=helper(root->right,subtree);
        return l||r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};