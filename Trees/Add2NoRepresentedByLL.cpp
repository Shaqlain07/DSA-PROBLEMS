class Solution
{
    public:
    Node* reverse(struct Node* head) {
        struct Node* curr=head;
        struct Node* prev=NULL;
        struct Node* agla;
        while(curr!=NULL) {
            agla=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agla;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* L1, struct Node* L2)
    {
        // code here
        L1=reverse(L1);
        L2=reverse(L2);
        int carry=0;
        struct Node* dummy=new Node(0);
        struct Node* temp=dummy;
        while(L1 || L2 || carry!=0) {
            int sum=0;
            if(L1) {
                sum+=L1->data;
                L1=L1->next;
            }
            if(L2) {
                sum+=L2->data;
                L2=L2->next;
            }
                sum+=carry;
                carry=sum/10;
                sum=sum%10;
            
            
            Node* root=new Node(sum);
            temp->next=root;
            temp=temp->next;
        }
        struct Node* head=reverse(dummy->next);
        return head;
    }
};
