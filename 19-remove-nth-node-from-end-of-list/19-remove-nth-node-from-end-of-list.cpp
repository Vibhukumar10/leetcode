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
        ListNode *fast=head,*prev=head;
        for(int i=0;i<n;i++) {
            fast=fast->next;
        }
        
        if(!fast) {
            ListNode *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        
        while(fast->next) {
            fast=fast->next;
            prev=prev->next;
        }
        
        ListNode *curr=prev->next;
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};