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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector <int> res;
        if(root == NULL)
            return res;
        int max_level = -1, current_level;
        queue <pair <TreeNode*, int> > q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            current_level = q.front().second;
            q.pop();
            if(current_level > max_level)
            {
                res.push_back(temp->val);
                max_level = current_level;
            }
            if(temp->right)
                q.push(make_pair(temp->right,current_level+1));
            if(temp->left)
                q.push(make_pair(temp->left,current_level+1));
        }
        return res;
    }
};
