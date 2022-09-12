class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zero=0;
        int one=0;
        int two=0;
        Node* temp=head;
        while(temp!=NULL) {
            if(temp->data==0) {
                zero++;
            }
            else if(temp->data==1) {
                one++;
            }
            else if(temp->data==2) {
                two++;
            }
            temp=temp->next;
        }
        Node* curr=head;
        while(zero--) {
            curr->data=0;
            curr=curr->next;
        }
        while(one--) {
            curr->data=1;
            curr=curr->next;
        }
        while(two--) {
            curr->data=2;
            curr=curr->next;
        }
        return head;
        
    }
};
