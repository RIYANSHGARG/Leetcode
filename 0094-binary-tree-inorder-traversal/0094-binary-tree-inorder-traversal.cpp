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
    void rec(TreeNode *root, vector<int> &ans){
        if(root==NULL)  return ;
        rec(root->left,ans);
        ans.push_back(root->val);
        rec(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // rec(root,ans);
        // return ans;
      
        // iteratively
        // if(!root)   return {};
        // TreeNode *node=root;
        // stack<TreeNode *> st;
        
        // vector<int> ans;
        
        // while(true){
        //     if(node){st.push(node);node=node->left;}
        //     else{
        //         if(st.empty())  break;
        //         node=st.top();
        //         st.pop();
        //         ans.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return ans;
        
        
//          Morris traversal
        if(!root)   return {};
        vector<int> ans;
        TreeNode *cur = root;
        while(cur!=NULL){
            if(!cur->left){
                ans.push_back(cur->val);
                cur=cur->right;
            }else{
                TreeNode *prev = cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};