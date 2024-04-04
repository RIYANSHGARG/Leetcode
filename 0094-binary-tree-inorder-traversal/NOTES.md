//     }
// }
// return in;
//  All in one stack
if(root==NULL)  return {};
stack<pair<TreeNode *,int>> s;
vector<int> pre,in,post;
s.push({root,1});
while(!s.empty()){
TreeNode *node = s.top().first;
int l=s.top().second;
s.pop();
if(l==1){
pre.push_back(node->val);
s.push({node,2});
if(node->left)  s.push({node->left,1});
}
else if(l==2){
in.push_back(node->val);
s.push({node,3});
if(node->right) s.push({node->right,1});
}else{
post.push_back(node->val);
}
}
return in;