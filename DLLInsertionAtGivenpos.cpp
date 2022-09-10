//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   //head can't be null here because we have to insert a node 
   //after pth node(so there should to be a node)
   Node* root=new Node(data);//Node created from data
   Node* temp=head;
   while(pos--) {
       temp=temp->next;
   }
   root->next=temp->next;
   root->prev=temp;
   if(temp->next!=NULL) {
   temp->next->prev=root;
   }
   temp->next=root;

   
   
   
}
