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
//entire base, if the left is smaller than the root, and right is bigger than the root, recurse over the left and right since the condition will prove correct if we keep going over and over

class Solution {
public:
    bool checker(TreeNode* root, long long low, long long high) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= high || root->val <= low) {
            return false;
        }
        return checker(root->right, root->val, high) && checker(root->left, low, root->val);

    }
    bool isValidBST(TreeNode* root) {  
        return checker(root, LLONG_MIN, LLONG_MAX);
    }
};
/*
 bool valid = true;
        if (root->right != nullptr && root->left == nullptr) {
            return root->right->val > root->val;
        }
        if (root->left != nullptr && root->right == nullptr) {
            return root->left->val < root->val;
        }
        if (root->left == nullptr) {
            return valid;
        }
        if (root->right == nullptr) {
            return valid;
        }

        if (!(root->right->val > root->val)) {
            valid = false;
        }
        if (!(root->left->val < root->val)) {
            valid = false;
        }
        bool right = isValidBST(root->left);
        bool left = isValidBST(root->right);
        return right && left;
        */
        