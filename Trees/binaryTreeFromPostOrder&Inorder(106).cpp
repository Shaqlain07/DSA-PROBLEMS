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
    TreeNode* helper(vector<int> &inorder,vector<int> &postorder,int inS,int inE,int postS,int postE) {
        //base case
        if(inS>inE || postS>postE) return NULL;
        int rootD=postorder[postE];
        //find root in inorder
        int i=0;
        for(;i<inorder.size();i++) {
            if(inorder[i]==rootD) break;
        }
        //find left subtree from inorder & postorder
        int leftinS=inS;
        int leftinE=i-1;
        int leftpostS=postS;
        int leftpostE=leftinE+leftpostS-leftinS;
        //find right subtree from inorder & postorder
        int rightinS=i+1;
        int rightinE=inE;
        int rightpostS=leftpostE+1;
        int rightpostE=postE-1;
        //construct root
        TreeNode* root=new TreeNode(rootD);
        //call on left & right subtree and connect with root
        root->left=helper(inorder,postorder,leftinS,leftinE,leftpostS,leftpostE);
        root->right=helper(inorder,postorder,rightinS,rightinE,rightpostS,rightpostE);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return helper(inorder,postorder,0,n-1,0,n-1);
    }
};
