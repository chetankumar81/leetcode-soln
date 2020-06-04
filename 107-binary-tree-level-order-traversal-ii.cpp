#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        stack<vector<int>> lvl_stack;
        vector<vector<int>> res;
        q.push(root);

        if (!root)
            return res;

        while (!q.empty())
        {
            vector<int> level;
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                root = q.front();
                q.pop();

                level.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }

            lvl_stack.push(level);
        }

        while (!lvl_stack.empty())
        {
            res.push_back(lvl_stack.top());
            lvl_stack.pop();
        }
        return res;
    }
};