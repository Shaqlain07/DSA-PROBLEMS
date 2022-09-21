class Solution {
public:
    //right boundary except leaf
    void rightBoundary(Node* root,vector<int> &v) {
                if(root==NULL) {
            return;
        }
        if(root->right) {
            rightBoundary(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left) {//since we dont have left node then right node will become boundary
            rightBoundary(root->left,v);
            v.push_back(root->data);
            
        }
    }
    //print leaf nodes
    void printLeaf(Node* root,vector<int> &v) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            v.push_back(root->data);
        }
        if(root->left){
            printLeaf(root->left,v);
        }
        if(root->right){
            printLeaf(root->right,v);
        }
    }
    //left boundary node..except leaf nodes
    void leftBoundary(Node* root,vector<int> &v) {
        if(root==NULL) {
            return;
        }
        if(root->left) {
            v.push_back(root->data);
            leftBoundary(root->left,v);
        }
        else if(root->right) {//since we dont have left node then right node will become boundary
            v.push_back(root->data);
            leftBoundary(root->right,v);
            
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) {
            return ans;
        }
        ans.push_back(root->data);
        leftBoundary(root->left,ans);//gets left boundary node
        
        printLeaf(root->left,ans);
        printLeaf(root->right,ans);
        
        rightBoundary(root->right,ans);
        return ans;
    }
};
