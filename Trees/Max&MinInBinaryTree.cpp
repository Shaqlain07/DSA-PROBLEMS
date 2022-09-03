class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        //base case
        if(root==NULL) {
            return INT_MIN;
        }
        int Max=INT_MIN;
        if(root->data > Max) {
            Max=root->data;
        }
        int Max1=findMax(root->left);
        int Max2=findMax(root->right);
        
        return max(Max,max(Max1,Max2));
    }
    int findMin(Node *root)
    {
        //code here
        if(root==NULL) {
            return INT_MAX;
        }
        int Min=INT_MAX;
        if(root->data < Min) {
            Min=root->data;
        }
        int Min1=findMin(root->left);
        int Min2=findMin(root->right);
        
        return min(Min,min(Min1,Min2));
    }
};
