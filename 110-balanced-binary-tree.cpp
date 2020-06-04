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
    int height(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return(
            abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)
        );
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
    cout << sl.height(root);
    return 0;
}