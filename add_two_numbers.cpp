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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int c = 0,carry = 0,sum,mod;
        ListNode *dummy = new ListNode();
        ListNode *temp;
        while(l1 != NULL && l2 != NULL)
        {
            c++;
            sum = (l1->val) + (l2->val) + carry;
            mod = sum % 10;
            carry = sum / 10;
            if(c > 1)
            {
                ListNode *node = new ListNode();
                node->val = mod;
                node->next = NULL;
                temp->next = node;
                temp = node;
            }
            else
            {
                dummy->val = mod;
                dummy->next = NULL;
                temp = dummy;   
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            ListNode *node = new ListNode();
            sum = (l1->val) + carry;
            mod = sum % 10;
            carry = sum / 10;
            node->val = mod;
            node->next = NULL;
            temp->next = node;
            temp = node;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            ListNode *node = new ListNode();
            sum = (l2->val) + carry;
            mod = sum % 10;
            carry = sum / 10;
            node->val = mod;
            node->next = NULL;
            temp->next = node;
            temp = node;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode *node = new ListNode();
            node->val = carry;
            node->next = NULL;
            temp->next = node;
            temp = node;
        }
        return dummy;
    }
};
