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
    void findMinDepth(TreeNode* root, int &min_depth, int curr_depth) {
        if (root->left == nullptr && root->right == nullptr) {
            min_depth = min(min_depth, curr_depth);
            return;
        }
        if (root->left) {
        findMinDepth(root->left, min_depth, curr_depth+1);  
        }
        if (root->right) {
        findMinDepth(root->right, min_depth, curr_depth+1);  
        }

    }
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int min_depth = INT_MAX;
        findMinDepth(root, min_depth, 0);
        return min_depth+1;
    }
};