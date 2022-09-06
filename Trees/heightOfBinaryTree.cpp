class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL) {
            return 0;
        }
        int htL=height(node->left);
        int htR=height(node->right);
        
        return 1+max(htL,htR);
    }
};
