Node* reverseDLL(Node * head)
{
    //Your code here
    //edge case 
    if(head==NULL && head->next==NULL) {
        return head;
    }
    Node* curr=head;
    while(curr!=NULL) {
        head=curr;//update currrent
        Node* temp=curr->next;//maintaining curr next
        Node* dummy=curr->prev;//maintaining curr previous
        curr->prev=curr->next;
        curr->next=dummy;
        curr=temp;
    }
    return head;
}
