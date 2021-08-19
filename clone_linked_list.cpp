/*1st approach
Time Complexity - O(n)
Space Complexity - O(n)*/
Node *copyList(Node *head)
{
    //Write your code here
    Node* newhead, *temp, *node;
    map<Node*,Node*> mp;
    int c = 0;
    temp = head;
    while(temp)
    {
        c++;
        if(c == 1)
        {
            node = new Node(temp->data);
            newhead = node;
        }
        else
            node = new Node(temp->data);
        mp.insert({temp,node});
        temp = temp->next;
    }
    for(auto it : mp)
    {
        mp[it.first]->next = mp[it.first->next];
        mp[it.first]->arb = mp[it.first->arb];
    }
    return newhead;
}

/*1st approach
Time Complexity - O(n)
Space Complexity - O(1)*/
Node *copyList(Node *head)
{
    //Write your code here
    Node* newhead, *temp, *node ,*original, *copy;
    temp = head;
    int c = 0;
    while(temp)
    {
        node = new Node(temp->data);
        node->next = temp->next;
        temp->next = node;
        temp = temp->next->next;
    }
    temp = head;
    while(temp)
    {
        temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
        temp = temp->next->next;
    }
    original = head, newhead = copy = head->next;
    while(original && copy)
    {
        original->next = original->next->next;
        original = original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        copy = copy->next;
    }
    return newhead;
}
