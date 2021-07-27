/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
vector<int> postOrder(Node* root) 
{
    // code here
    vector<int> vec;
    if(!root)
        return vec;
    stack<Node*> stk;
    while(root != NULL || !stk.empty())
    {
        while(root != NULL)
        {
            stk.push(root);
            vec.push_back(root->data);
            root = root->right;
        }
        root = stk.top();
        stk.pop();
        root = root->left;
    }
    reverse(vec.begin(),vec.end());
    return vec;
}
