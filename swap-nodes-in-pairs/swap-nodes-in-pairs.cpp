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
    ListNode* swapPairs(ListNode* head) {
        
//         if(!head || !head->next)
//             return head;
                
//         ListNode *newHead=head->next;
//         head->next=swapPairs(newHead->next);
//         newHead->next=head;
        
//         return newHead;
        
        if(head==NULL || head->next==NULL)
        return head;
        //make next store the node which is 2 nodes ahead
        ListNode *curr=head->next->next;
        //handling the first two nodes
        ListNode *prev=head;
        head=head->next;
        head->next=prev;
        //handling the remaining nodes 
        while(curr!=NULL && curr->next!=NULL)
        {
            prev->next=curr->next;
            prev=curr;
            ListNode *next=curr->next->next;
            curr->next->next=curr;
            //set curr as next (move ahead by 2 nodes)
            curr=next;
        }
        prev->next=curr;
        return head;
    }
};