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
    void rec(TreeNode *root,vector<int> &ans){
        if(!root)   return ;
        rec(root->left,ans);
        ans.push_back(root->val);
        rec(root->right,ans);
    }
    
    bool solve(vector<int> &vec, int &tar){
        int low=0,high=vec.size()-1;
        while(low<high){
            if(vec[low]+vec[high]==tar) return true;
            else if(vec[low]+vec[high]<tar) low++;
            else high--;    
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        rec(root,ans);
        return solve(ans,k);
    }
};