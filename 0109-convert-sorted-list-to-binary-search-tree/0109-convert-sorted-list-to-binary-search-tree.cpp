/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *BST(ListNode *head){
        if(head==NULL)  return NULL;
        if(!head->next){
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        
        ListNode *slow=head,*fast=head->next;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        int midval = slow->next->val;
        ListNode *first=head;ListNode *mid=slow->next;ListNode *second = slow->next->next;
        slow->next = NULL;
        
        TreeNode *root = new TreeNode(midval);
        
        TreeNode *lefts = BST(first);
        TreeNode *rights = BST(second);
        
        root->left = lefts;
        root->right = rights;
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root = BST(head);
        return root;
    }
};