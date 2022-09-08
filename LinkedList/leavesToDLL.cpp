int solve(Node* root ,Node* &head) {
    if(root==NULL) {
        return 0;
    }
    if(root->left==NULL && root->right==NULL) {//leaf nodes
          Node* temp=new Node(root->data);//Node created for LL
          if(head==NULL) {//first leaf node
              head=temp;
          }
          else {
              temp->left=head;
              head->right=temp;
              head=head->right;
          }
          return 1;
    }
    if(solve(root->left,head)) {
        root->left=NULL;//here modifing tree
    }
    if(solve(root->right,head)) {
        root->right=NULL;
    }
    return 0;//means we didn't get leaf nodes
}
// return the head of the DLL and remove those node from the tree as well.
Node * convertToDLL(Node *root){
    // add code here.
    Node* head=NULL;
    solve(root,head);
    while(head->left!=NULL) {
        head=head->left;
    }
    
    return head;
    
    
}
