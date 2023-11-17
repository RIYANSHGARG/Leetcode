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
    
    ListNode * Merge(ListNode *LL1 , ListNode *LL2){
        ListNode *ans = new ListNode(-1);
        ListNode *ansTail=ans;
        while(LL1 && LL2){
            if(LL1->val < LL2->val){
                ansTail->next=LL1;
                LL1=LL1->next;
                ansTail=ansTail->next;
            }else{
                ansTail->next=LL2;
                LL2=LL2->next;
                ansTail=ansTail->next;
            }
        }
        
        if(LL1) ansTail->next=LL1;
        if(LL2) ansTail->next=LL2;
        
        return ans->next;
        
    }
    
    ListNode * sorted(ListNode *head){
        
        if(!head || !head->next)    return head;
        
        ListNode *slow = head,*fast = head->next;
        while(fast->next && fast->next->next){
            slow=slow->next;fast=fast->next->next;
        }
        ListNode *lefts = head, *rights = slow->next;
        slow->next=NULL;
        
        ListNode *left = sorted(lefts);
        ListNode *right = sorted(rights);
        
        ListNode *ans = Merge(left , right);
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;
        return sorted(head);
    }
};