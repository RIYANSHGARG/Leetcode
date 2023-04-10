/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "boost/lexical_cast.hpp"
// using boost::lexical_cast;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)  return "";
        string ans="";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                if(q.front()!=NULL){
                    ans+=to_string(q.front()->val)+",";
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else    ans+="#,";
                q.pop();
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)  return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        int a=stoi(str);

        // int b=lexical_cast<int>(str);
        cout<<endl<<str<<" "<<a;
        
        TreeNode *root=new TreeNode(a);
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")    temp->left=NULL;
            else{
                TreeNode *LeftNode=new TreeNode(stoi(str));
                temp->left=LeftNode;
                q.push(temp->left);
            }

            getline(s,str,',');
            if(str=="#")    temp->right=NULL;
            else{
                TreeNode *RightNode=new TreeNode(stoi(str));
                temp->right=RightNode;
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));