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
    void helper(TreeNode* root,string curr,int &ans) {
        //leaf nodes
        if(root->left==NULL && root->right==NULL) {
            curr+=to_string(root->val);
            ans+=stoi(curr);
        }

        if(root->left) {
            helper(root->left,curr+to_string(root->val),ans);
        }
        if(root->right) {
            helper(root->right,curr+to_string(root->val),ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        helper(root,"",ans);
        return ans;
    }
};
