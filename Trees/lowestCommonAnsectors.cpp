Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL) return root;
   Node* temp = root;
   while(true){
    if(n1<temp->data&&n2<temp->data) temp = temp->left;
    else if(n1>temp->data&&n2>temp->data) temp = temp->right;
    else return temp;
   }
   ///optional
   return root;
}
