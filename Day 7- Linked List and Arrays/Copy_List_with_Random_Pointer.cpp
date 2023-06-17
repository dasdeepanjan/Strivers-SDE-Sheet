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

        Node* curr=head;
        while(curr){
            Node* next= curr->next;
            curr->next= new Node(curr->val);
            curr->next->next=next;
            curr=next;
        }

        curr=head;

        while(curr){
            if(curr->random && curr->next){
                (curr->next)->random=(curr->random)->next;
            }
            curr=curr->next->next;
        }

        Node* dummy= new Node(0);
        Node* helper=dummy;
        
        while(head){
            helper->next=head->next;
            helper=helper->next;

            head->next=head->next->next;
            head=head->next;
        }

        return dummy->next;
        
    }
};