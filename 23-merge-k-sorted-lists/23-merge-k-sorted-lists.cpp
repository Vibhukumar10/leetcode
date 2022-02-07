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
    ListNode* mergeTwoLists(ListNode *head1,ListNode *head2)
    {
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        
        ListNode *tail=NULL,*head=NULL;
        if(head1->val < head2->val)
        {
            tail=head=head1;
            head1=head1->next;
        }
        else
        {
            tail=head=head2;
            head2=head2->next;
        }
        
        
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                tail->next=head1;
                head1=head1->next;
            }
            else
            {
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        
        while(head1)
        {
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        while(head2)
        {
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
        
        
        ListNode *curr=mergeTwoLists(lists[0],lists[1]);
        for(int i=2;i<n;i++)
        {
            curr=mergeTwoLists(curr,lists[i]);
        }
        
        return curr;
    }
};