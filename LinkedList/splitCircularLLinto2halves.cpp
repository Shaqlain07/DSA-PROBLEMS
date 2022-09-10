//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    //find middle of Node
    Node* torto=head;
    Node* hier=head;
    while(hier->next!=head && hier->next->next!=head ) {
        torto=torto->next;
        hier=hier->next->next;
    }
    if(hier->next->next==head) {
        hier=hier->next;
    }
    Node* temp=torto->next;
    torto->next=head;
    *head1_ref=head;
    
    *head2_ref=temp;
    hier->next=*head2_ref;
}
