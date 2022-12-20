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
    void inorder(TreeNode* root,vector<int> &v) {
        //base case
        if(root==NULL) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);  
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        //find the min diff
        int mn=INT_MAX;
        for(int i=0;i<v.size()-1;i++) {
            mn=min(mn,(v[i+1]-v[i]));
        }
        return mn;
        

    }
};
