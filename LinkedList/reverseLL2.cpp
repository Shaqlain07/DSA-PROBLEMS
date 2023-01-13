/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* fwd;

        while(curr) {
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //iterate to left
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=1;
        while(cnt!=left) {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        ListNode* start=curr;//storing the left node
        //iterate to right
        while(cnt!=right) {
            curr=curr->next;
            cnt++;
        }
        ListNode* rest=curr->next;//storing next node of right to connect afterwards
        curr->next=NULL;

        //calling the fn to reverse the list
        ListNode* newHead=reverse(start);
        if(prev!=NULL) {
            prev->next=newHead;//1->4
        }
        //iterate to tail 2
        curr=newHead;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=rest;//2->5
        if(left==1) {
            return newHead;
        }
        else {
            return head;
        }
    }
};
