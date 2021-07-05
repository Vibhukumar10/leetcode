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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> m;
        ListNode *it=head;
        while(it!=NULL)
        {
            if(m.find(it)!=m.end())
            {
                return true;
            }
            m.insert(it);
            it=it->next;
        }
        return false;
    }
};