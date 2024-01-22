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
    int maxLevelSum(TreeNode* root) {
        if(!root)   return 0;
        int level=1,final_Sum=INT_MIN , final_Level=0;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                sum+=node->val;
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>final_Sum){final_Sum=sum;final_Level=level;}
            level++;
        }
        
        return final_Level;
    }
};