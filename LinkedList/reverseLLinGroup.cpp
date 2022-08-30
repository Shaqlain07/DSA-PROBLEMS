class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node* prev=NULL;
        struct node* curr=head;
        int c=0;
        node* agla;
        while(curr!=NULL && c<k) {
             agla=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agla;
            c++;
        }
        if(agla!=NULL) {
            head->next=reverse(agla,k);
        }
        return prev;
    }
};
