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
    TreeNode* helper(vector<int> &preorder,vector<int> &inorder,int preS,int preE,int inS,int inE)  {
            //base case
            if(inS>inE || preS>preE) return NULL;

            int rootD=preorder[preS];
            //find this root in inoder
            int i=0;
            for(;i<inorder.size();i++) {
                if(inorder[i]==rootD) break;
            }
            //Now,find left subtree from inorder and preorder
            int leftinS=inS;
            int leftinE=i-1;
            int leftpreS=preS+1;
            int leftpreE=leftinE+leftpreS-leftinS;
            //Now,find the right subtree from inorder and preorder
            int rightinS=i+1;
            int rightinE=inE;
            int rightpreS=leftpreE+1;
            int rightpreE=preE;
            //construct root
            TreeNode* root=new TreeNode(rootD);
            //call on leftSubtree & rightSubtree and connect with root
            //it will return root with pre and in
            root->left=helper(preorder,inorder,leftpreS,leftpreE,leftinS,leftinE);
            root->right=helper(preorder,inorder,rightpreS,rightpreE,rightinS,rightinE);

            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};
