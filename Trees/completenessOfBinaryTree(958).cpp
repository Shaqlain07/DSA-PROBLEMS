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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        bool lastLine=false;//to indicate the last line
    
        while(!q.empty()) {
            int n=q.size();
            //if u got the last line then next line should not start
            //and if it is starting all elements should to be NULL
            if(lastLine==true) {
                while(!q.empty()) {
                    if(q.front()!=NULL) return false;
                    q.pop();
                }
                break;
            }
            
            
        
            for(int i=0;i<n;i++) {
                TreeNode* front=q.front();
                
                q.pop();
                //if u got null then u should not get node furthur
                if(lastLine==true && front!=NULL) return false;
                if(front==NULL) {
                    //it mean it has to be last line
                    lastLine=true;
                    continue;
                }
                
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};
