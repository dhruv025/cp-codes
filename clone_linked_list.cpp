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
