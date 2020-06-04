#include <bits/stdc++.h>
using namespace std;
#define bool int

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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        else
        {
            int subSum = sum - root->val;
            if (!root->left && !root->right)
                return subSum == 0;
            return hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum);
        }
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
    cout << (sl.hasPathSum(root, sum) == 1 ? true : false);
    return 0;
}