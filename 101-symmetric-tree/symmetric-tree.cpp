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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || findIsSymmetric(root->left, root->right);
    }

    bool findIsSymmetric(TreeNode* left, TreeNode* right){
        if(right == NULL || left == NULL){
            return left == right;
        }

        if(left->val != right->val){
            return false;
        }

        return findIsSymmetric(left->left, right->right)
                && findIsSymmetric(left->right, right->left);
    }
};