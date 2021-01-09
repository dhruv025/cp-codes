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
    void solve2(TreeNode *root2, vector <int> &vec2)
    {
        if(root2 == NULL)
            return;
        solve2(root2->left,vec2);
        vec2.push_back(root2->val);
        solve2(root2->right,vec2);
    }
    void solve1(TreeNode *root1, vector <int> &vec1)
    {
        if(root1 == NULL)
            return;
        solve1(root1->left,vec1);
        vec1.push_back(root1->val);
        solve1(root1->right,vec1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector <int> vec1, vec2, ans;
        solve1(root1,vec1);
        solve2(root2,vec2);
        int n = vec1.size(), m = vec2.size(), i = 0, j = 0;
        while(i < n && j < m)
        {
            if(vec1[i] <= vec2[j])
            {
                ans.push_back(vec1[i]);
                i++;
            }
            else if(vec1[i] > vec2[j])
            {
                ans.push_back(vec2[j]);
                j++;
            }
        }
        while(i < n)
        {
            ans.push_back(vec1[i]);
            i++;
        }
        while(j < m)
        {
            ans.push_back(vec2[j]);
            j++;
        }
        return ans;    
    }
};
