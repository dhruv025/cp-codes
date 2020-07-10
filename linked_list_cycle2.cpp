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
    ListNode *detectCycle(ListNode *head) 
    {
        bool c = 0;
        if(head == NULL || head ->next == NULL)
            return NULL;
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast != NULL && fast ->next != NULL)
        {
            slow = slow ->next;
            fast = fast ->next ->next;
            if(slow == fast)
            {
                c = 1;
                break;
            }
        }
        if(!c)
            return NULL;
        ListNode* temp = head;
        while(slow != temp)
        {
            slow = slow ->next;
            temp = temp ->next;
        }
        return slow;
    }
};
