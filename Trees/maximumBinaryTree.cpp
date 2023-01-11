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
    int maxindex(vector<int> &nums,int s,int e) {
        int mx=-1;
        int ans=INT_MIN;
        for(int i=s;i<=e;i++) {
            if(ans<nums[i]) {
                mx=i;
                ans=nums[i];
            }
        }
        return mx;
    }
    TreeNode* helper(vector<int> &nums,int s,int e) {
        //base case
        if(s>e) return NULL;
        if(s==e) {
            TreeNode* root=new TreeNode(nums[s]);
            return root;
        }
        //finding maximum element
        int mi=maxindex(nums,s,e);

        //create the root node with max element
        TreeNode* root=new TreeNode(nums[mi]);
        root->left=helper(nums,s,mi-1);
        root->right=helper(nums,mi+1,e);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        return helper(nums,s,e);
    }
};
