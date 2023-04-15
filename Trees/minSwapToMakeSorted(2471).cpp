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
    int countOperation(vector<int> nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<v.size();i++) {
            if(v[i].second==i) continue;
            count++;
            swap(v[i],v[v[i].second]);
            i--;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res=0;
        while(!q.empty()) {
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++) {
                TreeNode* front=q.front();
                q.pop();
                if(front->left!=NULL) {
                    q.push(front->left);
                }
                if(front->right!=NULL) {
                    q.push(front->right);
                }
                v.push_back(front->val);
            }
            res+=countOperation(v);
        }
        return res;
    }
};
