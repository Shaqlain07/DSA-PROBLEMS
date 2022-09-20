class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> v;
        Node* curr=root;
        while(curr!=NULL) {
            if(curr->left==NULL) {
                v.push_back(curr->data);
                curr=curr->right;
            }
            else {
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr) {//to find right most node on left subtree
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=curr;//connect the thread
                    curr=curr->left;
                }
                else {//thread is connected previously and we need to remove it
                    prev->right=NULL;
                    v.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return v;
    }
};
