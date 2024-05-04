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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            long long int sum=0,count=0;;
            for(int i=0;i<s;i++){
                TreeNode *newNode = q.front();
                sum+=newNode->val;
                count++;
                q.pop();
                
                if(newNode->left)   q.push(newNode->left);
                if(newNode->right)  q.push(newNode->right);
                
            }
            ans.push_back((double)sum/count);
        }
        return ans;
    }
};