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
    
    int findBottomLeftValue(TreeNode* root) {
        if((!root->left && !root->right))  return root->val;
        int ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            ans=q.front()->val;
            for(int i=0;i<s;i++){
                TreeNode *temp=q.front();
                q.pop();
                
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};