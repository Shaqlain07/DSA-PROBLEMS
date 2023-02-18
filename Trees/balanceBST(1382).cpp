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
    TreeNode* solve(vector<int> v,int s,int e) {
        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        //creating root with the mid node
        TreeNode* root=new TreeNode(v[mid]);
        root->left=solve(v,s,mid-1);
        root->right=solve(v,mid+1,e);
        return root;
    }
    void inorder(TreeNode* root,vector<int> &v) {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return solve(v,0,v.size()-1);
    }
};
