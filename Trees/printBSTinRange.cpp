class Solution {
  public:
  
    void helper(Node* root,int k1,int k2,vector<int> &v) {
        if(root==NULL) {
            return;
        }
        if(root->data >=k1 && root->data <=k2) {//checking that it is in range or not
            v.push_back(root->data);
        }
        if(root->data > k1) {//there r elements in range which r smaller than root
            helper(root->left,k1,k2,v);
        }
        if(root->data < k2) {
            helper(root->right,k1,k2,v);
        }
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here 
        vector<int> v;
        helper(root,low,high,v);
         sort(v.begin(),v.end());
         return v;
        
    }
};
