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
    bool flag=false;
    void solve(TreeNode* root,int targetSum,int currSum) {
        currSum+=root->val;
        if(root->left==NULL && root->right==NULL) {
            if(currSum==targetSum) {
                flag=true;
            }
        }
        if(root->left) {
            solve(root->left,targetSum,currSum);
        }
        if(root->right) {
            solve(root->right,targetSum,currSum);
        }
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) {
            return false;
        }
        int currSum=0;
        solve(root,targetSum,currSum);
        if(flag==true) {
            return true;
        }
        return false;
    }
};
