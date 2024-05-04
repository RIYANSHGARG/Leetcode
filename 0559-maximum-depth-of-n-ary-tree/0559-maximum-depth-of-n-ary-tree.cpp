/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int rec(Node *root){
        if(!root)   return 1;
        
        int height=0;
        for(auto i:root->children){
            height=max(height,1+rec(i));
        }
        return height;
    }
    
    int maxDepth(Node* root) {
        if(!root)   return 0;
        return rec(root)+1;
    }
};