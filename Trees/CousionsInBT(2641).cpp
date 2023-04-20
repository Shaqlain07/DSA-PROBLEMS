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
public:unordered_map<int,set<TreeNode*>> mp;
    void solve(TreeNode* root,int depth,TreeNode* parent) {
        if(!root) return;
        mp[depth+1].insert(parent);
        if(root->left) {
            solve(root->left,depth+1,root);
        }
        if(root->right) {
            solve(root->right,depth+1,root);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        solve(root,0,NULL);//this will create map which will have all the parent node with its depth
        for(auto& it:mp) {
            set<TreeNode*> v=it.second;
            int size=v.size();
            auto itr=v.begin();
            if(size>1) {//there are more than 1 parent so we have cousions
                int total=0;
                while(itr!=v.end()) {//it will add all the children of parents
                    TreeNode* p=*itr;
                    if(p->left) {
                        total+=p->left->val;
                    }
                    if(p->right) {
                        total+=p->right->val;
                    }
                    itr++;
                }
                itr=v.begin();
                while(itr!=v.end()) {
                    TreeNode* p=*itr;
                    int sum=0;
                    if(p->left){
                        sum+=p->left->val;
                    }
                    if(p->right) {
                        sum+=p->right->val;
                    }
                    if(p->left) {
                        p->left->val=total-sum;
                    }
                    if(p->right) {
                        p->right->val=total-sum;
                    }
                    itr++;
                }
            }
            else if(*itr!=NULL) {
                if((*itr)->left) {
                    (*itr)->left->val=0;
                }
                if((*itr)->right) {
                    (*itr)->right->val=0;
                }
            }
        }
        //seperate for root
        root->val=0;
        return root;
    }
};
