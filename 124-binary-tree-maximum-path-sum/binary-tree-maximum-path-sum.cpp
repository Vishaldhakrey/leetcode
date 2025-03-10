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
    int maxSum;
    int findMaxSumPath(TreeNode* root) {
        if (root == NULL ) {
            return 0;
        }

        int left = findMaxSumPath(root->left);
        int right = findMaxSumPath(root->right);

        int max_sum_below_root = left + right + root->val;

        int max_one_side = max(left, right) + root->val;

        int max_sum_root = root->val;

        maxSum = max({maxSum, max_sum_below_root, max_one_side, max_sum_root});

        return max(max_sum_root, max_one_side);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        findMaxSumPath(root);

        return maxSum;
    }
};