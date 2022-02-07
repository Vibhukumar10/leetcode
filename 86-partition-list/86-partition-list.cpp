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
    ListNode* partition(ListNode* head, int x) {
        ListNode *beforeHead=new ListNode(0);
        ListNode *afterHead=new ListNode(0);
        ListNode *beforeTail=beforeHead;
        ListNode *afterTail=afterHead;
        
        while(head)
        {
            if(head->val<x)
            {
                beforeTail->next=head;
                beforeTail=beforeTail->next;                
            }
            else
            {
                afterTail->next=head;
                afterTail=afterTail->next;
            }
            head=head->next;
        }
        afterTail->next=NULL;
        beforeTail->next=afterHead->next;
        
        return beforeHead->next;
    }
};