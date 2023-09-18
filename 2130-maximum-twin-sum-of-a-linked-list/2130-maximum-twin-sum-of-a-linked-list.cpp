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
    
    ListNode *traverse(ListNode *head){
        ListNode *slow=head,*fast=head->next;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode *reverse(ListNode *head){
        ListNode *cur=head,*nex=head->next,*prev=NULL;
        while(nex){
            cur->next=prev;
            prev=cur;
            cur=nex;
            nex=nex->next;
        }
        cur->next=prev;
        return cur;
    }
    
    int pairSum(ListNode* head) {
        ListNode *Middle = traverse(head);
        Middle->next=reverse(Middle->next);
        Middle = Middle->next;
        int sum=0;
        while(Middle){
            sum=max(sum,head->val+Middle->val);
            head=head->next;
            Middle=Middle->next;
        }
        return sum;
    }
};