/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
vector<int> preOrder(Node* root)
{
    //code here
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
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
    return vec;
}
