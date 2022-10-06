class Solution {
public:
    void recursion(TreeNode* root,int level,vector<int> &ans) {
        if(root==NULL) {//base case
            return;
        }
        if(level==ans.size()) {
            ans.push_back(root->val);
        }
        if(root->right) {
            recursion(root->right,level+1,ans);
        }
        if(root->left) {
            recursion(root->left,level+1,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
       recursion(root,0,ans);
       return ans;
        
    }
};
