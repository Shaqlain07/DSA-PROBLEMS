class Solution {
public:
    bool check(TreeNode* rootL,TreeNode* rootR) {
        if(rootL==NULL || rootR==NULL) {//if one is null then other has to be null for true 
            return rootL==rootR;//if it correct then it will return true
        }
        if(rootL->val!=rootR->val) {
            return false;
        }
        
        return check(rootL->left,rootR->right)//if both return true then only it will return 
                &&                              //true
               check(rootL->right,rootR->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left,root->right);
    }
};
