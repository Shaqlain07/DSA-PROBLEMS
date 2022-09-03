class Solution{
  public:
  
    //Function for merging
    Node* merge(Node* l1, Node* l2) {
        Node* root=new Node(0);
        Node* dummy=root;
        while(l1!=NULL && l2!=NULL) {
            if(l1->data < l2->data) {
                dummy->next=l1;  //connected to LL
                dummy=dummy->next;//update dummy
                l1=l1->next;//update l1
            }
            else {
                dummy->next=l2;  //connected to LL
                dummy=dummy->next;//update dummy
                l2=l2->next;//update l1
            }
        }
        if(l1!=NULL) {
            dummy->next=l1;
        }
        else {
            dummy->next=l2;
        }
        return root->next;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* root=arr[0];
           for(int i=1;i<K;i++) {
               root=merge(root,arr[i]);
           }
           return root;
    }
};
