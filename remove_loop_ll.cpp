class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return;
        Node* fast, *slow;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow == head)
        {
            while(slow->next != head)
            {
                slow = slow->next;
            }
            slow->next = NULL;
        }
        if(slow == fast)
        {
            slow = head;
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next=NULL;
        }
    }
};
