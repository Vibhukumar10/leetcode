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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *prev=NULL,*curr=head;
        while(curr) {
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail=head;

        int count=1;
        while(tail && count<k) {
            tail=tail->next;
            count++;
        }

        if(!tail) return head;
        
        ListNode *next=tail->next;
        tail->next=NULL;
        ListNode *newHead=reverse(head);
        head->next=reverseKGroup(next,k);

        return newHead;
    }
};