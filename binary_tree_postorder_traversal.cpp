/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        if(!root)
            return vec;
        stack<TreeNode*> stk1,stk2;
        stk1.push(root);
        while(!stk1.empty())
        {
            TreeNode* curr = stk1.top();
            stk1.pop();
            if(curr->left)
                stk1.push(curr->left);
            if(curr->right)
                stk1.push(curr->right);
            stk2.push(curr);
        }
        while(!stk2.empty())
        {
            vec.push_back(stk2.top()->val);
            stk2.pop();
        }
        return vec;
    }
};
