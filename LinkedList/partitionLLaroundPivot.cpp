struct Node* partition(struct Node* head, int x) {
    // code here
    Node* smallH=NULL;
    Node* smallT=NULL;
    Node* equalH=NULL;
    Node* equalT=NULL;
    Node* greaterH=NULL;
    Node* greaterT=NULL;
    
    while(head) {
        if(head->data ==x) {
            if(equalH==NULL) {
                equalH=equalT=head;
            }
            else {
                equalT->next=head;
                equalT=equalT->next;
            }
        }
        else if(head->data < x) {
            if(smallH==NULL) {
                smallH=smallT=head;
            }
            else {
                smallT->next=head;
                smallT=smallT->next;
            }
        }
        else if(head->data > x){
            if(greaterH==NULL) {
                greaterH=greaterT=head;
            }
            else {
                greaterT->next=head;
                greaterT=greaterT->next;
            }
        }
        head=head->next;
    }
    if(greaterT!=NULL) {
        greaterT->next=NULL;
    }
    //linking 3 list
    if(smallT==NULL) {//smaller list is empty
        if(equalT==NULL) {//equal list is also empty
            return greaterH;
        }
        equalT->next=greaterH;
        return equalH;
    }
    //small list is non-empty,equal is empty
    if(equalT==NULL) {
        smallT->next=greaterH;
        return smallH;
    }
    //both small and equal are present
    smallT->next=equalH;
    equalT->next=greaterH;
    return smallH;
}
