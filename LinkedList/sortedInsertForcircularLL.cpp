// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node* Ndata=new Node(data);
       Node* temp=head;
       if(temp->data>data) {//at head node
           Ndata->next=head;
           Node* dummy=head;
           while(dummy->next!=head) {
               dummy=dummy->next;
           }
           dummy->next=Ndata;
           head=Ndata;
           return head;
       }
       
       while(temp->next->data <= data) {
           temp=temp->next;
       }
       Ndata->next=temp->next;
       temp->next=Ndata;
       return head;
    }
};
