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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push(root);
        

        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                TreeNode* front=q.front();
                q.pop();
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
                v.push_back(front->val);
            }
            ans.push_back(v);
            //pop  v untill becomes empty
            while(!v.empty()) {
                v.pop_back();
            }
        }
        return ans;

    }
};
