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
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr){ 
            return 0;
        }
        //Recursive Approach
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
        // int max_depth = 0;

        // queue<TreeNode*>q;
        // q.push(root);

        // while(!q.empty()){
        //     int levelLength = q.size();
        //     for(int i=0; i<levelLength; i++){
        //         TreeNode* currentNode = q.front();
        //         q.pop();

        //         if(currentNode->left != nullptr){
        //             q.push(currentNode->left);
        //         }
        //         if(currentNode->right != nullptr){
        //             q.push(currentNode->right);
        //         }
        //     }
        //     max_depth += 1;
        // }
        // return max_depth;
    }
};