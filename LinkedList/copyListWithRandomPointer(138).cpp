/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //store  the copy of node next to curr to node
        Node* curr=head;
        while(curr) {
            //before connecting store the next of curr
            Node* fwd=curr->next;
            //make a copy of curr node
            Node* root=new Node(curr->val);
            //connect to curr
            curr->next=root;
            //connect the copy to fwd
            root->next=fwd;
            curr=fwd;
        }
        //Now,connect the random of copy node
         curr=head;
        while(curr) {
            if(curr->random==NULL) {
                curr->next->random=NULL;
            }
            else {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        //Now,separate both the list
        Node* dummy=new Node(NULL);
        Node* copy=dummy;
        Node* item1=head;
        
        while(item1) {
            Node* item2=item1->next->next;
            //connect the copy
            copy->next=item1->next;
            //connect original list
            item1->next=item2;
            //iterate the copy node
            copy=copy->next;
            //iterate the original node
            item1=item2;
            
        }
        return dummy->next;
    }
};
