class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
          Node *temp=head_ref;
     int c=0;
     while(temp!=NULL){
         c++;
         if(c==x){
             if(temp->prev==NULL){
                 head_ref=temp->next;
                 temp->prev=NULL;
             }else if(temp->next==NULL){
                 temp->prev->next=temp->next;
             }else{
                 temp->next->prev=temp->prev;
                 temp->prev->next=temp->next;
             }
             delete temp;
             return head_ref;
         }
         temp=temp->next;
         
     }
    }
};
