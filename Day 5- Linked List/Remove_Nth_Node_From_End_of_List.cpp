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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len=0;
        ListNode* curr=head;

        while(curr!=NULL){
            len++;
            curr=curr->next;
        }

        if(len==1){
            return NULL;
        }
        
        int remove= len-n;

        ListNode* prev=head;
        while(remove>1){
            prev=prev->next;
            remove--;
        }

        curr=prev->next;
        if(remove!=0 && curr!=NULL){
        prev->next=curr->next;
        delete(curr);
        }
        else{
            head=head->next;
            delete(prev);
            
        }

        return head;
    }
};