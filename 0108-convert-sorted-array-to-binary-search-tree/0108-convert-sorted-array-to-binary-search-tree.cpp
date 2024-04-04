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
    TreeNode *rec(int st,int end, vector<int> &nums){
        if(st==end) return new TreeNode(nums[st]);
        
        int node=(st+end)/2;
        TreeNode *root=new TreeNode(nums[node]);
        if(node==st)    root->left=NULL;
        else    root->left=rec(st,node-1,nums);
        if(node==end)   root->right=NULL;
        else    root->right=rec(node+1,end,nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root=rec(0,nums.size()-1,nums);
        return root;
    }
};