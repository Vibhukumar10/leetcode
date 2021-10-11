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
    
    int getLength(ListNode *head)
    {
        int count=0;
        while(head)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len=getLength(head);
        if(len==0 || len==1)
            return head;
        k%=len;
        if(k==0)
            return head;
        
        ListNode *slow=head,*fast=head;
        while(k-- && fast)
            fast=fast->next;
        
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode * new_head=slow->next;
        slow->next=NULL;
        fast->next=head;
        head=new_head;
        return head;
    }
};