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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode*, pair<int, int>>>q;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;

            int fir = temp.second.first;
            int sec = temp.second.second;

            nodes[fir][sec].insert(node->val);

            if(node->left!=NULL) q.push({node->left, {fir-1, sec+1}});
            if(node->right!=NULL) q.push({node->right, {fir+1, sec+1}});
        }

        vector<vector<int>>ans;

        for(auto m : nodes){
            vector<int>col;
            for(auto n : m.second){
                col.insert(col.end(), n.second.begin(), n.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};