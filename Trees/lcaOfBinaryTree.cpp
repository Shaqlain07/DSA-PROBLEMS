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
  //last intersection node from top,iterate dfs if u find a node return node, if u find both the node return root
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) {
            return root;
        }
        
        TreeNode* lft=lowestCommonAncestor(root->left,p,q);
        TreeNode* rgt=lowestCommonAncestor(root->right,p,q);

        if(lft==NULL && rgt==NULL) return NULL;
        if(lft!=NULL && rgt!=NULL) return root;
        if(!lft) {
            return rgt;
        }
        else {
            return lft;
        }
    }
};
