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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head){
            return head;
        }

        ListNode* curr=head;
        int cnt=1;

        while(curr->next!=NULL){
            curr=curr->next;
            cnt++;
        }

        curr->next=head;

        k%=cnt;
        cnt=cnt-k;

        while(cnt>0){
            curr=curr->next;
            cnt--;
        }
        ListNode* newHead= curr->next;
        curr->next=NULL;

        return newHead;

    }
};