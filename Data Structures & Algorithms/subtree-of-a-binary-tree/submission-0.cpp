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
    bool checker(TreeNode* current, TreeNode* current_sub) {
        // bool isSame;
        // if (current->left == NULL && current->right == NULL) {
        //     isSame = (current->val == current_sub->val) && isSame;
        //     return isSame;
        // }
        // if (current->val == current_sub->val) {
        //     if (current->right != NULL && current_sub->right != NULL) {
        //         checker(current->right, current_sub->right);
        //     }
        //     if (current->left != NULL && current_sub->left != NULL) {
        //         checker(current->left, current_sub->left);
        //     }
        // }
        // else {
            
        // }
        if (current == nullptr && current_sub == nullptr) {
            return true;
        }
        else if (current == nullptr || current_sub == nullptr) {
            return false;
        }
        else if (current->val != current_sub->val) {
            return false;
        }
        
        return checker(current->right, current_sub->right) && checker(current->left, current_sub->left);
    }



    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* current = root;
        TreeNode* current_sub = subRoot;
        // if ((current->right == NULL && current->left == NULL) && (current_sub->right == NULL && current_sub->left == NULL)) {
        //     return current->val == current_sub->val;
        // }
        // while (current->right != NULL && current->left != NULL) {
        // returnable = checker(current, current_sub);
        if (current == nullptr) {
            return false;
        }
        else if (checker(current, current_sub)) {
            return true;
        }
        else {
            return isSubtree(current->left, current_sub) || isSubtree(current->right, current_sub);
        }
    }
};
