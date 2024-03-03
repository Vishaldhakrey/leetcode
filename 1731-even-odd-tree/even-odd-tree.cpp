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
    bool isEvenOddTree(TreeNode* root) {
    if (root == nullptr)
            return false;

        bool even = true;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto levelSize = q.size();
            auto prev = even ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

            for (auto i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (even) {
                    if (curr->val % 2 == 0 || curr->val <= prev)
                        return false;
                } else {
                    if (curr->val % 2 != 0 || curr->val >= prev)
                        return false;
                }

                prev = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            
            even = !even;
        }

        return true;
    }
};