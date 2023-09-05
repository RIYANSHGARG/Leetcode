/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node *head2=new Node(0);
        Node *tail=head2;
        while(temp!=NULL){
            Node *nex=temp->next->next;
            tail->next=temp->next;
            temp->next=nex;
            tail=tail->next;
            temp=nex;
            
        }
        return head2->next;
    }
};