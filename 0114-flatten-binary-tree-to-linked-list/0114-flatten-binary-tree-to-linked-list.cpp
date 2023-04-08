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
    
    void flatten(TreeNode* root) {

        // Method 1 : Recursive
        // if(root==NULL)  return ;
        
        // if(root->right) flatten(root->right);
        // if(root->left) flatten(root->left);

        // root->right=prev;
        // root->left=NULL;
        // prev=root;

        // Method 2 : iterative
        // if(root==NULL)   return ;
        // stack<TreeNode *> s;
        // s.push(root);
        // while(!s.empty()){
        //     TreeNode *cur=s.top();
        //     s.pop();

        //     if(cur->right!=NULL)    s.push(cur->right);
        //     if(cur->left!=NULL)   s.push(cur->left);

        //     if(!s.empty())  cur->right=s.top();
        //     cur->left=NULL;
        // }

        // Method 3 : Morris Traversal
        if(root==NULL)   return ;
        TreeNode *cur=root;
        while(cur!=NULL){
            if(cur->left!=NULL){
                TreeNode *prev=cur->left;
                while(prev->right!=NULL){prev=prev->right;}
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};