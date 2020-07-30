/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
   vector <int> res;
   if(root == NULL)
        return res;
    multimap <int,int> mp;
    queue <pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        mp.insert(pair<int,int>(hd,temp->data));
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it : mp)
        res.push_back(it.second);
    return res;
}
