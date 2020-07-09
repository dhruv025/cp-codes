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
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head ->next == NULL)
            return true;
        ListNode* p = head, *q = head, *start_sec;
        while(1)
        {
            p = p->next->next;
            if(p == NULL)
            {
                start_sec = q->next;
                break;
            }
            if(p->next == NULL)
            {
                start_sec = q->next->next;
                break;
            }
            q = q->next;
        }
        q->next = NULL;
        ListNode* prev = NULL, *curr = start_sec, *nextNode;
        while(curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        bool c = 0;
        while(head != NULL)
        {
            if(head->val == prev->val)
            {
                head = head->next;
                prev = prev->next;
            }
            else
            {
                c = 1;
                break;
            }
        }
        if(c)
            return false;
        else
            return true;
    }
};
