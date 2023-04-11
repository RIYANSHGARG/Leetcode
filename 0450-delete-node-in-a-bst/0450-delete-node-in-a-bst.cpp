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
    
    TreeNode *Helper(TreeNode *root){
        if(!root->right)    return root->left;
        else if(!root->left)    return root->right;
        TreeNode * dummy = root->right;
        while(dummy->left){
            dummy=dummy->left;
        }
        dummy->left=root->left;
        return root->right;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)      return NULL;
        TreeNode *temp=root;
        
        if(root->val == key)    return Helper(root);
        
        while(root){
            if(root->val > key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=Helper(root->left);
                }else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val == key){
                    root->right = Helper(root->right);
                }
                else{
                    root=root->right;
                }
            }
        }
        return temp;
    }
};