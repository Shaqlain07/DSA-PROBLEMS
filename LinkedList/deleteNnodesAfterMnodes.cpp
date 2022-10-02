class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        Node* curr=head;
        while(curr) {
            //skip M nodes
            for(int i=1;i<M && curr!=NULL ;i++) {
                curr=curr->next;
            }
            //if we reached end of list then return
            if(curr==NULL) {
                return;
            }
            Node* t=curr->next;
            //delete N nodes
            for(int i=1;i<=N && t!=NULL ;i++) {
                t=t->next;
            }
            curr->next=t;
            curr=t;
        }
    }
};
