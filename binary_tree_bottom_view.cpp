/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   vector <int> res;
   if(root == NULL)
        return res;
    map <int,int> mp;
    queue <pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        mp[hd] = temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it : mp)
        res.push_back(it.second);
    return res;
}

