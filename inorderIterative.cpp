/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
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
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            vec.push_back(root->data);
            root = root->right;
        }
        return vec;
    }
};
