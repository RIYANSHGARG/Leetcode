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
    int rec(TreeNode *root, bool &ans){
        if(ans==false)  return 0;
        if(root==NULL)  return 0;
            
        int left_height = rec(root->left,ans);
        int right_height = rec(root->right, ans);
        
        if(ans) ans=(abs(left_height-right_height) <=1)?true:false;
        
        return 1+max(left_height,right_height);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        bool ans=true;
        rec(root,ans);
        return ans;
    }
};