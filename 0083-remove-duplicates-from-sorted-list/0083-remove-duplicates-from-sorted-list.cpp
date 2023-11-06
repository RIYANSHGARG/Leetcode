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
        ListNode *prev = new ListNode(-101);
        prev->next=head;
        ListNode *cur = head;
        while(cur){
            if(prev->val==cur->val){
                prev->next=cur->next;
                cur=prev->next;
                continue;
            }
            prev=prev->next;
            if(prev->next)  cur=prev->next;
            else    break;
        }
        return head;
    }
};