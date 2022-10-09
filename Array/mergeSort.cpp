Node* mergeSort(Node* head) {

        vector<int>v;

        Node* temp=head;

        while(temp!=NULL){

            v.push_back(temp->data);

            temp=temp->next;

        }

        sort(v.begin(),v.end());

        Node* ans=head;

        int i=0;

        while(ans!=NULL){

          ans->data=v[i];

          ans=ans->next;

          i++;

        }

       return head;

    }

