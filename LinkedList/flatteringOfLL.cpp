Node* merge(Node* L1,Node* L2) {
    Node* temp=new Node(0);
    Node* dummy=temp;
    
    while(L1!=NULL && L2!=NULL) {
        if(L1->data < L2->data) {
            dummy->bottom=L1;
            dummy=dummy->bottom;
            L1=L1->bottom;
        }
        else {
            dummy->bottom=L2;
            dummy=dummy->bottom;
            L2=L2->bottom;
        }
    }
    if(L1!=NULL) {
        dummy->bottom=L1;
    }
    else {
        dummy->bottom=L2;
    }
    return temp->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   // base case
   if(root==NULL || root->next==NULL) {
       return root;
   }
   
    root->next=flatten(root->next);//at return new list will be linked to root
   root=merge(root,root->next); //after merging we will update the root
   
   return root;
}
