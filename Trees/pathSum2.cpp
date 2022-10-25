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
    void solve(TreeNode* root,int targetSum,int currSum,vector<int> currPath,vector<vector<int>> &ans) {
        currPath.push_back(root->val);
        currSum+=root->val;
        
        if(root->left==NULL && root->right==NULL) {
            if(currSum==targetSum) {
                ans.push_back(currPath);
            }
        }
        if(root->left) {
            solve(root->left,targetSum,currSum,currPath,ans);
        }
        if(root->right) {
            solve(root->right,targetSum,currSum,currPath,ans);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) {
            return ans;
        }
        vector<int> currPath;
        int currSum=0;
        solve(root,targetSum,currSum,currPath,ans);
        return ans;
    }
};
