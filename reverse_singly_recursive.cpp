#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
Node* dummy = (Node*)malloc(sizeof(Node));
Node* p = dummy;
Node* head, *q;
void insert(int x)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    p->next = newnode;
    p = newnode;
}
void reverse(Node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    reverse(p->next);
    q = p->next;
    q->next = p;
    p->next = NULL;
}
int main()
{
    int n,a;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        insert(a);
    }
    head = dummy->next;
    reverse(head);
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

