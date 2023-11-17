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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head;
        bool wasSame=false;
        
        ListNode *dummy = new ListNode(-301);
        dummy->next=head;
        ListNode *prev = dummy , *cur = head;
        
        while(cur){
            if(cur->val == prev->val){
                cur=cur->next;
                wasSame=true;
                continue;
            }
            if(!wasSame){
                cur=cur->next;
                prev=prev->next;
            }
            else{
                prev->val = cur->val;
                prev->next=cur->next;
                cur=cur->next;
                wasSame = false;
            }
        }
        if(prev->next==NULL)    return dummy->next;
        
        if(prev->next && prev->val == prev->next->val)    prev->next = NULL;
        ListNode *temp = dummy;
        while(temp){
            if(temp->next && temp->next->val == prev->val){
                temp->next=NULL;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};