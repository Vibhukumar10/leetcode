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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*q=head;
        if(head==NULL)
            return NULL;

        while(q!=NULL&&q->val==val)
        {
            ListNode*p=q;
            q=q->next;
            delete p;
        }
        
        head=q;
        
        while(q && q->next)
        {
            if(q->next->val==val)
            {
                ListNode*temp=q->next;
                q->next=temp->next;
                delete temp;
            }
            else
                q=q->next;
        }
        return head;
    }
};