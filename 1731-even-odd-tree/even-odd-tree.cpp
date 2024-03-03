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
    // if (root == nullptr)
    //         return false;

        // bool even = true;
        // std::queue<TreeNode*> q;
        // q.push(root);

        // while (!q.empty()) {
        //     auto levelSize = q.size();
        //     auto prev = even ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

        //     for (auto i = 0; i < levelSize; i++) {
        //         TreeNode* curr = q.front();
        //         q.pop();

        //         if (even) {
        //             if (curr->val % 2 == 0 || curr->val <= prev)
        //                 return false;
        //         } else {
        //             if (curr->val % 2 != 0 || curr->val >= prev)
        //                 return false;
        //         }

        //         prev = curr->val;

        //         if (curr->left)
        //             q.push(curr->left);
        //         if (curr->right)
        //             q.push(curr->right);
        //     }
            
        //     even = !even;
        // }

        if(root == nullptr)
            return false;
            
        std::queue<TreeNode*> queue;
        queue.push(root);
        int level = -1;

        while(!queue.empty()) {
            level++;
            int size = queue.size();
            int prev = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                if(level == 0 && curr->val % 2 == 0)                        
                    return false;

                if(i == 0) {
                    if((level % 2 == 0 && curr->val % 2 == 1) || (level % 2 == 1 && curr->val % 2 == 0))                    
                        prev = curr->val;
                    else
                        return false;
                }
                else {                    
                    if(level % 2 == 1) {
                        if(curr->val % 2 == 0 && prev > curr->val)
                            prev = curr->val;
                        else
                            return false;
                    }
                    else {
                        if(curr->val % 2 == 1 && prev < curr->val)
                            prev = curr->val;
                        else
                            return false;
                    }
                }
                                        
                if(curr->left != nullptr)
                    queue.push(curr->left);
                
                if(curr->right != nullptr)
                    queue.push(curr->right);
            }
        }
        
        return true;
    }
};