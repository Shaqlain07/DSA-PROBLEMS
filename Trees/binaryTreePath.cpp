class Solution {
public:
    void recursion(TreeNode* root,string st,vector<string> &ans) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {//leaf node
            st+=to_string(root->val);//add data to string
            ans.push_back(st);
        }
        st+=to_string(root->val)+"->";
        if(root->left) {
            recursion(root->left,st,ans);
        }
        if(root->right) {
            recursion(root->right,st,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string st="";
        recursion(root,st,ans);
        
        return ans;
    }
};
