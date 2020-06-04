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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        if(nums.size() == 0)
            return nullptr;
        if(nums.size() == 1){
            root->val = nums[0];
        }else {
            int mid = nums.size()/2;
            root->val = nums[mid];
            vector<int> lval = vector<int>(nums.begin(), nums.begin()+mid);
            vector<int> rval = vector<int>(nums.begin()+mid+1,nums.end());
            root->left = sortedArrayToBST(lval);
            root->right = sortedArrayToBST(rval);
        }
        return root;
    }
};

/* class Solution {
public:
    TreeNode* BST(vector<int> &nums, int start, int end){
        if(start > end){
            return NULL;
        }

        int mid = (end + start)/2;
        
        TreeNode *root = new TreeNode();
        root->val = nums[mid];
        
        root->left = BST(nums, start, mid - 1);
        root->right = BST(nums, mid + 1, end);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
}; */