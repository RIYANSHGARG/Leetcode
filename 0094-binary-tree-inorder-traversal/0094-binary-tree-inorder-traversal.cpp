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
vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Method 1 : recursive
        // if(root==NULL)  return {};
        // inorderTraversal(root->left);
        // v.push_back(root->val);
        // inorderTraversal(root->right);
        // return v;

        // Methdo 2 : Iterative
        // if(root==NULL)  return {};
        // vector<int> ans;
        // TreeNode * node=root;
        // stack<TreeNode *> s;
        // while(true){
        //     if(node!=NULL){
        //         s.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(s.empty())  break;
        //         node=s.top();
        //         s.pop();
        //         ans.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return ans;

        // Method 3 : Finding all pre in and post order in go using 1 stack
        // if(root==NULL)  return {};
        // stack<pair<TreeNode *,int>> s;
        // vector<int> pre,in,post;
        // s.push({root,1});
        // while(!s.empty()){
        //     auto it=s.top();
        //     s.pop();
        //     if(it.second==1){
        //         pre.push_back(it.first->val);
        //         it.second++;
        //         s.push(it);
        //         if(it.first->left!=NULL)    s.push({it.first->left,1});
        //     }
        //     else if(it.second==2){
        //         in.push_back(it.first->val);
        //         it.second++;
        //         s.push(it);
        //         if(it.first->right!=NULL)   s.push({it.first->right,1});
        //     }
        //     else{
        //         post.push_back(it.first->val);
        //     }
        // }
        // return in;

        // Method 4 : Morris Traversal
        // vector<int> in;
        // TreeNode *cur=root;
        // while(cur){
        //     if(!cur->left){
        //         in.push_back(cur->val);
        //         cur=cur->right;
        //     }else{
        //         TreeNode *prev=cur->left;
        //         while(prev->right && prev->right!=cur)    prev=prev->right;
        //         if(!prev->right)    {prev->right=cur;cur=cur->left;}
        //         else{prev->right=NULL;in.push_back(cur->val);cur=cur->right;}
        //     }
        // }
        // return in;
        
        
        // practice :
        //  recursion         
        // if(!root)   return {};
        // inorderTraversal(root->left);
        // v.push_back(root->val);
        // inorderTraversal(root->right);
        // return v;
        
        //  iterative
        TreeNode *node = root;
        stack<TreeNode *> s;
        vector<int> in;
        while(true){
            if(node){
                s.push(node);
                node=node->left;
            }else{
                if(s.empty())   break;
                node = s.top();
                s.pop();
                in.push_back(node->val);
                node=node->right;
            }
        }
        return in;
    }
};