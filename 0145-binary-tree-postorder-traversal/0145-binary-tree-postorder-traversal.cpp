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
        rec(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // rec(root,ans);
        // return ans;
        
        // iteratively
        if(root==NULL)  return {};
        stack<TreeNode *> st,res;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            TreeNode *temp=st.top();
            st.pop();
            res.push(temp);
            if(temp->left)  st.push(temp->left);
            if(temp->right)  st.push(temp->right);
        }
        while(!res.empty()){
            ans.push_back(res.top()->val);
            res.pop();
        }
        return ans;
    }
};