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
    int solve(int max, TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        if(root->val >= max) {
            return 1 + solve(root->val, root->left) + solve(root->val, root->right);
        }
        return solve(max, root->left) + solve(max, root->right);
    }
    int goodNodes(TreeNode* root) {
        return solve(INT_MIN, root);
    }
};
