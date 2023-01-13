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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* ans=NULL;

        while(curr) {
            ListNode* start=curr;
            ListNode* rest=curr;
            int cnt=1;
            //iterate to end of kth node
            while(cnt!=k && curr->next!=NULL) {
                curr=curr->next;
                cnt++;
            }
        if(cnt!=k) {//we have less than k nodes
            prev->next=rest;//connecting the rest element
            break;
        }
        ListNode* temp=curr->next;//storing the next element
        curr->next =NULL;
        ListNode* newHead=reverse(start);
        if(prev!=NULL) {//connecting with previous group
            prev->next=newHead;
        }
        else {
            ans=newHead;
        }
        //iterate to tail
        curr=newHead;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        prev=curr;//1, tail to connect to head of next group
        curr=temp;//next element
    }
    return ans;
    }

};
