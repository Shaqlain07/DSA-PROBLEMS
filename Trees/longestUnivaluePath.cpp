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
    int res=0;
    int solve(TreeNode* root) {
        if(root==NULL) return 0;
        int l=solve(root->left);//
        int r=solve(root->right);

        int leftChild=0;//is left child is same as root
        int rightChild=0;
        if(root->left!=NULL && root->val==root->left->val) {
            leftChild=l+1;
        }
        if(root->right!=NULL && root->val==root->right->val) {
            rightChild=r+1;
        }
        res=max(res,leftChild+rightChild);
        return max(leftChild,rightChild);
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return  res;
    }
};
