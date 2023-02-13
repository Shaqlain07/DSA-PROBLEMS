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
    int helper(TreeNode* root) {
        //base case
        if(root==NULL) return 0;
        //call on left and right to find height
        int lh=helper(root->left);
        int rh=helper(root->right);
        //cases for unbalanced tree
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        //balanced case
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ans=helper(root);
        if(ans!=-1) {
            return true;
        }
        return false;
    }
};
