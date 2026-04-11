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
    int ans = INT_MIN;
public:
    int solve(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int sumLeft = root->val + left;
        int sumRight = root->val + right;
        ans = max({ans, sumLeft, sumRight, root->val + left + right});
        int temp = max(sumLeft, sumRight);
        if(temp < 0) return 0;
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
