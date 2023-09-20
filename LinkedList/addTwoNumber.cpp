// Your code goes here
        SinglyLinkedListNode* temp=new SinglyLinkedListNode(NULL);
        SinglyLinkedListNode* dummy=temp;
        int carry=0;
        while(l1 || l2 || carry) {
            int sum=0;
            if(l1) {
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2) {
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            SinglyLinkedListNode* root=new SinglyLinkedListNode(sum%10);
            dummy->next=root;
            dummy=dummy->next;
        }
        return temp->next;
