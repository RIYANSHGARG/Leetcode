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
    
    void rec(TreeNode *root, int level, vector<int> &ans){
        if(root==NULL)  return ;

        if(ans.size()==level)   ans.push_back(root->val);
        if(root->right!=NULL)    rec(root->right,level+1,ans);
        if(root->left!=NULL)    rec(root->left,level+1,ans);
    } 
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};

        vector<int> ans;
        rec(root,0,ans);
//         queue<pair<TreeNode *,int>> q;
//         q.push({root,0});
//         while(!q.empty()){
                        
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode * node = q.front().first;
//                 int level = q.front().second;
//                 q.pop();
//                 if(ans.size()==level)   ans.push_back(node->val);
//                 else    ans[level]=node->val;
                
//                 if(node->left)  q.push({node->left,level+1});
//                 if(node->right)  q.push({node->right,level+1});
//             }
//         }
        return ans;
    }
};