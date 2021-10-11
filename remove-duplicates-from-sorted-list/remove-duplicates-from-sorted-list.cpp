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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        while(head->next && head->val == head->next->val)
            head=head->next;
        
        ListNode *res=head;
        ListNode*curr=head;
        
        for(ListNode *it=curr;it!=NULL;it=it->next)
        {
            if(res->val!=it->val)
            {
                res->next=it;
                res=res->next;
            }
        }
        res->next=NULL;
        return head;
    }
};