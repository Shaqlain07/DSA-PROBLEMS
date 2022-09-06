class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head){
            return;
        }
        Node* prev=NULL;
        Node* curr=head;
        unordered_map<Node*,int> m;
        
        while(curr) {
            if(!m[curr]){
                m[curr]=1;
                prev=curr;
                curr=curr->next;
            }
            else {
                prev->next=NULL;
                break;
            }
        }
    }
};
