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
private:
    void inorder(TreeNode* root, int& counter, int k, int &kthSmallest)
        {
            if(!root || counter>=k) return;
            
            inorder(root->left, counter, k, kthSmallest);

            counter++;

            if(counter == k){
                kthSmallest = root->val;
                return;
            }
            inorder(root->right, counter, k, kthSmallest);
        }
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthSmallest = INT_MAX;

        int counter = 0;
        inorder(root, counter, k, kthSmallest);
        return kthSmallest;
    }
};