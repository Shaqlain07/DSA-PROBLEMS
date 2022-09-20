// This function should return head to the DLL
class Solution
{
    public: 
    void helper(Node* root,Node* &head,Node* &prev) {
        if(root==NULL) {
            return;
        }
        helper(root->left,head,prev);
        if(prev==NULL) {
            head=root;
            prev=root;
        }
        else {
            prev->right=root;
            root->left=prev;
            prev=root;//update prev
        }
        helper(root->right,head,prev);
    }
    
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head=NULL;
        Node* prev=NULL;//previous node used for connecting
        helper(root,head,prev);
        return head;
        
    }
};
