// Method 1 : recursive
// if(root==NULL)  return {};
// inorderTraversal(root->left);
// v.push_back(root->val);
// inorderTraversal(root->right);
// return v;
​
// Methdo 2 : Iterative
// if(root==NULL)  return {};
// vector<int> ans;
// TreeNode * node=root;
// stack<TreeNode *> s;
// while(true){
//     if(node!=NULL){
//         s.push(node);
//         node=node->left;
//     }
//     else{
//         if(s.empty())  break;
//         node=s.top();
//         s.pop();
//         ans.push_back(node->val);
//         node=node->right;
//     }
// }
// return ans;
​
// Method 3 : Finding all pre in and post order in go using 1 stack
// if(root==NULL)  return {};
// stack<pair<TreeNode *,int>> s;
// vector<int> pre,in,post;
// s.push({root,1});
// while(!s.empty()){
//     auto it=s.top();
//     s.pop();
//     if(it.second==1){
//         pre.push_back(it.first->val);
//         it.second++;
//         s.push(it);
//         if(it.first->left!=NULL)    s.push({it.first->left,1});
//     }