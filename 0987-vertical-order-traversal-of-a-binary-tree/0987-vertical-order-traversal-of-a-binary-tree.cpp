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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode *,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode *node = q.front().first;
            int vlevel = q.front().second.first;
            int hlevel = q.front().second.second;
            q.pop();
            
            m[vlevel][hlevel].insert(node->val);
            if(node->left)  q.push({node->left,{vlevel-1,hlevel+1}});
            if(node->right)  q.push({node->right,{vlevel+1,hlevel+1}});
        }
        
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> temp;
            for(auto j:i.second){
                
                for(auto k:j.second){
                    temp.push_back(k);
                }
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};