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
    ListNode* removeNodes(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            // ListNode* next = curr->next;
            // curr->next = prev;
            // prev = curr;
            // curr = next;
            swap(curr->next, prev);
            swap(prev, curr);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* tempPrev = dummyHead;
        curr = prev;

        while (curr != nullptr) {
            if (curr->val >= tempPrev->val) {
                tempPrev->next = curr;
                tempPrev = curr;
                curr = curr->next;
            } else {
                curr = curr->next;
            }
        }
        tempPrev->next = nullptr;

        ListNode *newPrev = nullptr, *newCurr = dummyHead->next;
        while (newCurr != nullptr) {
            // ListNode* next = newCurr->next;
            // newCurr->next = newPrev;
            // newPrev = newCurr;
            // newCurr = next;
            swap(newCurr->next, newPrev);
            swap(newPrev, newCurr);
        }

        return newPrev;
    }
};