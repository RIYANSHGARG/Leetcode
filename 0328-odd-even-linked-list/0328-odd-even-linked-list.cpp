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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode *cur=head,*nex=head->next;
        ListNode *dummy = new ListNode(0);
        dummy->next=nex;
        
        while(nex && nex->next){
            cur->next=nex->next;
            nex->next=cur->next->next;
            cur=cur->next;
            nex=nex->next;
        }
        cur->next=dummy->next;
        return head;
    }
};