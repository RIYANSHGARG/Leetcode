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
    void dfs(TreeNode *root, vector<int> &v,int &count){
        if(!root)   return ;
        if(root->val >= *max_element(v.begin(),v.begin()+v.size()-1)){count++;}
        
        if(root->left){
            v.push_back(root->left->val);
            dfs(root->left,v,count);
            v.pop_back();
        }
        if(root->right){
            v.push_back(root->right->val);
            dfs(root->right,v,count);
            v.pop_back();
        }
    }
    
    int goodNodes(TreeNode* root) {
        int count=0;
        vector<int> v;
        v.push_back(root->val);
        dfs(root, v,count);
        return count;
    }
};