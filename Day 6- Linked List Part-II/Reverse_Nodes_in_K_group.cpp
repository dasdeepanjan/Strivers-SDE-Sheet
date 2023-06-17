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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre =dummy , *curr=dummy, *next=dummy;

        int cnt=0;
        while(curr->next!=NULL){
            cnt++;
            curr=curr->next;
        }

        while(cnt>=k){
            curr=pre->next;
            next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=pre->next;
                pre->next=next;
                next=curr->next;
            }
            pre=curr;
            cnt-=k;
        }

        return dummy->next;


        
    }
};