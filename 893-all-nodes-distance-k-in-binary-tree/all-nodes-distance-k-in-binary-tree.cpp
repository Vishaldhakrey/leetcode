/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&track_Parent, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                track_Parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                track_Parent[curr->right] = curr;
                q.push(curr->right);
            }

        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>track_Parent;
        markParent(root, track_Parent, target);

        queue<TreeNode*>q;
        unordered_map<TreeNode* , bool>visited;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true; 
                }

                if(track_Parent[curr] && !visited[track_Parent[curr]]){
                    q.push(track_Parent[curr]);
                    visited[track_Parent[curr]] = true;
                }
            }
        } 
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};