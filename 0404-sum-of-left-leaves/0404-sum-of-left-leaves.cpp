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
    int rec(TreeNode *root,bool l){
        if(!root)   return 0;
        if(!root->left && !root->right){
            if(l)   return root->val;
            else    return 0;
        }
        
        
        int ans=0;
        ans+=rec(root->left,true);
        ans+=rec(root->right,false);
        return ans;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return rec(root,false);
    }
};