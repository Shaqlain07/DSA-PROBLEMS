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
public:
    void marked_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front=q.front();
            q.pop();
            if(front->left) {
                parent[front->left]=front;
                q.push(front->left);
            }
            if(front->right) {
                parent[front->right]=front;
                q.push(front->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        marked_parent(root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dis=0;
        while(!q.empty()) {
            if(dis++==k) {
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++) {
                TreeNode* front=q.front();
                q.pop();
                if(front->left && !visited[front->left] ) {
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right] ) {
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(parent[front] && !visited[parent[front]]) {
                    visited[parent[front]]=true;
                    q.push(parent[front]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* data=q.front();
            q.pop();
            ans.push_back(data->val);
        }
        return ans;
    }
};
