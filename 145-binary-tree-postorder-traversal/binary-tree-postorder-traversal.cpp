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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int>ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        st1.push(root);

        while(!st1.empty()){
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp);

            if(temp->left!=NULL) st1.push(temp->left);
            if(temp->right!=NULL) st1.push(temp->right);
        }
        while(!st2.empty()){
            root = st2.top();
            st2.pop();
            ans.push_back(root->val);
        }
        return ans;
    }
};