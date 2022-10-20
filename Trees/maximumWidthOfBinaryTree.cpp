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
    int widthOfBinaryTree(TreeNode* root) {
        //Edge case
        if(root==NULL) {
            return 0;
        }
        int width=0; //for updating width
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            int size=q.size();
            int minIdx=q.front().second;//finding min index at every level for overflow
            int first,last;
            for(int i=0;i<size;i++) {
                int cur_id=q.front().second-minIdx;//updating index
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) {
                    first=cur_id;
                }
                if(i==size-1) {
                    last=cur_id;
                }
                if(node->left) {
                    q.push({node->left,(long long)2*cur_id+1});
                }
                if(node->right) {
                    q.push({node->right,(long long)2*cur_id+2});
                }
            }
            width=max(width,last-first+1);//after every level updating the width
        }
        return width;
    }
};
