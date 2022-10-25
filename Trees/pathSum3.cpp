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
    void solve(TreeNode* root,int targetSum,vector<long long> path,int &count) {
        if(root==NULL) {
            return;
        }
        path.push_back(root->val);
        solve(root->left,targetSum,path,count);
        solve(root->right,targetSum,path,count);
        
        //we are back from our left and right child..backtrack
        long long currSum=0;
        for(int j=path.size()-1;j>=0;j--) {
            currSum+=path[j];
            if(currSum==targetSum) {
                count++;
            }
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) {
            return 0;
        }
        vector<long long> path;
        int count=0;
        solve(root,targetSum,path,count);
        return count;
    }
};
