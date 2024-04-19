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
    
    int move(TreeNode *root, bool leftMove){
        if(!root)   return 0;
        int count=0;
        TreeNode *temp=root;
        while(temp){
            if(temp->left && leftMove)  {count++;temp=temp->left;leftMove=!leftMove;}
            else if(temp->right && !leftMove)   {count++;temp=temp->right;leftMove=!leftMove;}
            else if( (!temp->left && leftMove) || (!temp->right && !leftMove))    break;
        }
        return count;
    }
    
    int rec(TreeNode *root){
        if(!root)   return 0;
        
        int leftMove=move(root,true);
        int rightMove=move(root,false); 
        
        return max(rec(root->left) , max(rec(root->right),max(leftMove,rightMove)));
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root)   return 0;
        return rec(root);
    }
};