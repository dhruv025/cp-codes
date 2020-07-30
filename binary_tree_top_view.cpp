//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    if(root == NULL)
        return;
    map <int,int> mp;
    queue <pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        if(mp.find(hd) == mp.end())
            mp[hd] = temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it : mp)
        cout<<(it).second<<" ";
}
