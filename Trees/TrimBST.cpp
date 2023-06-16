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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        if(root->val>=low && root->val<=high) {
            //create a node
            TreeNode* node=new TreeNode(root->val);
            if(root->val>low) {
                node->left=trimBST(root->left,low,high);
            }
            else {
                node->left=NULL;
            }
            if(root->val<high) {
                node->right=trimBST(root->right,low,high);
            }
            else {
                node->right=NULL;
            }
            return node;
        }
        else {
            TreeNode* nodeL=NULL;
            if(root->val>low) {
                nodeL=trimBST(root->left,low,high);
            }
            TreeNode* nodeR=NULL;
            if(root->val<high) {
                nodeR=trimBST(root->right,low,high);
            }
            if(nodeL!=NULL) {
                //iterate to last node
                TreeNode* temp=nodeL;
                while(temp->right!=NULL) {
                    temp=temp->right;
                }
                temp->right=nodeR;
                return nodeL;
            }
            return nodeR;
        }
    }
};
