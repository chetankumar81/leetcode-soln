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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left)
            return 1 + minDepth(root->right);
        if(!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};

int main()
{

    int sum = 21;

    /* Constructed binary tree is  
                10  
            / \  
            8 2  
        / \ /  
        3 5 2  
    */
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    Solution sl;
    cout << sl.minDepth(root);
    return 0;
}