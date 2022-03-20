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
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head->next) return NULL;
        
        ListNode *prev=NULL,*curr=head;
        
        while(curr)
        {
          ListNode *next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
        }
        
        return prev;    
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1) return head;
        
        ListNode *curr=head;
        int kNew=k-1;
        while(curr && kNew!=0) {
            curr=curr->next;
            kNew--;
        }
        
        if(curr) {            
            ListNode *temp=curr->next;
            curr->next=NULL;
            
            ListNode *newHead=reverse(head);
            
            head->next=reverseKGroup(temp,k); 
            return newHead;
        } else {
            return head;
        }
    }
};