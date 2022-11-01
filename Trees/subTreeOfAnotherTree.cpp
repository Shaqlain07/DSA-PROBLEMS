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
    bool sameTree(TreeNode* p,TreeNode* q) {
        if(p==NULL || q==NULL) {
            return p==q;
        }
        if(p->val==q->val) {
            return (sameTree(p->left,q->left) && sameTree(p->right,q->right));
        }
        return false;
    }
    void solve(TreeNode* root,TreeNode* subRoot) {
        if(root==NULL) {
            return;
        }
        if(root->val==subRoot->val) {
            if(sameTree(root,subRoot)) {
                flag=true;
            }
        }
        solve(root->left,subRoot);
        solve(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solve(root,subRoot);
        return flag;
    }
};
