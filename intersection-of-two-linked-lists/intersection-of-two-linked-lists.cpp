/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        int diff=abs(lenA-lenB);
        ListNode *a_pointer=headA,*b_pointer=headB;
        if(lenA>=lenB)
            while(diff--)
                a_pointer=a_pointer->next;
        else
            while(diff--)
                b_pointer=b_pointer->next;
        
        while(a_pointer!=b_pointer)
        {
            a_pointer=a_pointer->next;
            b_pointer=b_pointer->next;
        }
        return a_pointer;
    }
};