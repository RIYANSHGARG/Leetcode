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
    void rec(TreeNode *root, int &ans, string &num){
        num+=to_string(root->val);
        if(!root->left && !root->right){
            int value = stoi(num,0,2);
            ans+=value;
            return;
        }
        
        if(root->left){
            rec(root->left,ans,num);
            if(!num.empty())    num.pop_back();
        }
        
        if(root->right){
            rec(root->right,ans,num);
            if(!num.empty())    num.pop_back();
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string number="";
        int ans=0;
        rec(root,ans,number);
        return ans;
    }
};