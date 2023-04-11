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
    int count=0;
    void sumKHelper(TreeNode *root, int &k, vector<int> &path){
        if(!root)   return ;

        path.push_back(root->val);
        sumKHelper(root->left,k,path);
        sumKHelper(root->right,k,path);
        
        long long temp=0;
        for(int i=path.size()-1;i>=0;i--){
            temp+=path[i];
            if(temp == k)   count++;
        }
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        sumKHelper(root, targetSum, path);
        return count;
    }
};