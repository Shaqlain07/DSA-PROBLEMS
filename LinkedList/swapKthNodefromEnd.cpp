class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       //edge case
       if(head==NULL || head->next==NULL || head->next->next==NULL) {
           return;
       }
       Node* odd=head; //iterating odd node
       Node* even=head->next;
       Node* temp=even; //iterating even node
       
       while(odd->next!=NULL && temp->next!=NULL) {
           if(odd->next->next!=NULL) { //connecting odd nodes
               odd->next=odd->next->next;
               odd=odd->next; //iterating over odd
           }
           else {
               odd->next=NULL;
           }
           if(temp->next->next!=NULL) { //connecting even nodes
               temp->next=temp->next->next;
               temp=temp->next;
           }
           else {
               temp->next=NULL;
           }
       }
       odd->next=even;
    }
};
